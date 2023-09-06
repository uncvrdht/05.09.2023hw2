#include <iostream>
using namespace std;

class Fraction
{
private:

	int top;
	int bot;

public:

	void Init()
	{

		cout << "Введите числитель дроби: " << endl;
		cin >> top;


		cout << "Введите знаменатель дроби: " << endl;
		cin >> bot;
		system("cls");
	}

	int GetTop()
	{
		return top;
	}

	int GetBot()
	{
		return bot;
	}

	void Print()
	{
		cout << top << endl << "-" << endl << bot << endl << endl;
	}

	void Selection(Fraction part1, Fraction part2)
	{
		char selection;
		cout << "Выберите нужную операцию: " << endl;
		cout << "1. Сложение" << endl;
		cout << "2. Вычитание" << endl;
		cout << "3. умножение" << endl;
		cout << "4. Деление" << endl;
		cin >> selection;
		switch (selection)
		{

		case '1':
			Add(part1, part2);
			break;

		case '2':
			Sub(part1, part2);
			break;

		case '3':
			Mul(part1, part2);
			break;

		case '4':
			Div(part1, part2);
			break;

		default:
			break;
		}
	}

	void Add(Fraction part1, Fraction part2)
	{
		if (part1.GetBot() == part2.GetBot())
		{
			top = part1.GetTop() + part2.GetTop();
			bot = part1.GetBot();
		}
		else
		{
			top = part1.GetTop() * part2.GetBot() + part2.GetTop() * part1.GetBot();
			bot = part1.GetBot() * part2.GetBot();
		}
	}

	void Sub(Fraction part1, Fraction part2)
	{
		if (part1.GetBot() == part2.GetBot())
		{
			top = part1.GetTop() - part2.GetTop();
			bot = part1.GetBot();
		}
		else
		{
			top = part1.GetTop() * part2.GetBot() - part2.GetTop() * part1.GetBot();
			bot = part1.GetBot() * part2.GetBot();
		}

	}

	void Mul(Fraction part1, Fraction part2)
	{
		top = part1.GetTop() * part2.GetTop();
		bot = part1.GetBot() * part2.GetBot();
	}

	void Div(Fraction part1, Fraction part2)
	{
		top = part1.GetTop() * part2.GetBot();
		bot = part1.GetBot() * part2.GetTop();
	}

};


int main()
{
	setlocale(LC_ALL, "ru");
	Fraction part1;
	Fraction part2;
	Fraction part3;


	part1.Init();
	part2.Init();
	part1.Print();
	part2.Print();
	part3.Selection(part1, part2);
	part3.Print();

}

