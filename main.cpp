#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int Q_NO = 1;
int CORRECT = 0;
int WRONG = 0;
bool ask[10] = {true, true, true, true, true, true, true, true, true, true};

void display_random_question();
void display();
void question(string question, string a, string b, string c, string d, char correct_answer);
void result();

int main()
{
    display();
    return 0;
}

void display()
{
    system("cls");
    cout<<"Question no: "<<Q_NO<<endl<<endl;
    display_random_question();
}

void display_random_question()
{
    srand(time(0));
    bool is_question_remaining = false;
    for(int i=0; i<10; i++)
    {
        if(ask[i])
        {
            is_question_remaining = true;
            break;
        }
    }
    while (is_question_remaining)
    {
        int no = rand()%10;
        if(ask[no])
        {
            ask[no] = false;
            switch(no)
            {
            case 0:
                question("Negara yang berbatasan dengan Indonesia di bagian selatan adalah...", 
                "Australia", "Bangladesh", "China", "Denmark", 'a');
                break;
            
            case 1:
                question("Binatang khas Indonesia dan hanya ada di Indonesia adalah...", 
                "Harimau", "Kuda", "Beruang", "Komodo", 'd');
                break;

            case 2:
                question("Serangga yang memiliki rasa solidaritas tinggi adalah...", 
                "Belalang", "Semut", "Kupu-kupu", "Lalat", 'b');
                break;
            
            case 3:
                question("Akar dari 25 adalah...", 
                "2", "5", "6", "8", 'b');
                break;
            
            case 4:
                question("Ibukota negara Indonesia adalah...", 
                "Jakarta", "Bandung", "Bekasi", "Bali", 'a');
                break;
            
            case 5:
                question("Monumen terkenal di kota Paris adalah menara...", 
                "Astra", "Monas", "Pisa", "Eiffel", 'd');
                break;
            
            case 6:
                question("Pusat dari tata surya adalah...", 
                "Matahari", "Mars", "Bumi", "Venus", 'a');
                break;

            case 7:
                question("Contoh alat musik yang dipetik...", "Drum", "Piano", "Gitar", "Trompet", 'c');
                break;
            
            case 8:
                question("Tumbuhan berduri yang kebanyakan tumbuh pada daerah gersang seperti gurun adalah...", 
                "Rumput", "Kaktus", "Mangga", "Mawar", 'b');
                break;
            
            case 9:
                question("Lukisan Mona Lisa merupakan karya dari...", 
                "Pablo Picasso", "Titian", "Leonardo da Vinci", "Vincent van Gogh", 'c');
                break;
            }
        }
    }
    result();
}

void result()
{
    system("cls");
    cout<<"Total question : "<<Q_NO-1<<endl;
    cout<<"Correct answer : "<<CORRECT<<endl;
    cout<<"Wrong answer   : "<<WRONG<<endl;
    if(CORRECT>WRONG)
        cout<<"Pass"<<endl;
    else if(CORRECT<WRONG)
        cout<<"Fail"<<endl;
    else
        cout<<"Tie"<<endl;
}

void question(string question, string a, string b, string c, string d, char correct_answer)
{
    cout<<question<<endl;
    cout<<"A. "<<a<<endl;
    cout<<"B. "<<b<<endl;
    cout<<"C. "<<c<<endl;
    cout<<"D. "<<d<<endl;
    char answer;
    cout<<"\nMasukkan jawaban: ";
    cin>>answer;

    if(answer == correct_answer)
        CORRECT++;
    else
        WRONG++;
    Q_NO++;
    display();
}