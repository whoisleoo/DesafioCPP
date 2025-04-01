/*

Um programa em C++ com dois jogos, um de Dois ou Um e outro de Par ou Impar.
Seu diferencial é o uso de BOTS, ou seja, o jogo é totalmente baseado em chances, não existe estrategias para ganhar, apenas jogue
e deixe que a sua sorte decida sua vitória.

*/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <windows.h>

using namespace std;

bool primeiraVitoria = false;
bool segundaVitoria = false;
int option;
int jogadaPJ;
int escolhaPJ;
string trofeu[] = {
    "             ___________",
    "            '._==_==_=_.'",
    "            .-\\:      /-.",
    "           | (|:.     |) |",
    "            '-|:.     |-'", 
    "              \\::.    /",
    "               '::. .'",
    "                 ) (",
    "               _.' '._"
};

//Função de definição de cor.
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    vector<int> jogadores(2);

    //Jogo de Dois ou Um.
    do {
        for (int i = 0; i < 2; i++) {
            jogadores[i] = rand() % 2 + 1;
        }

        setColor(15); 
        cout << "Digite um número entre (2 ou 1): ";
        cin >> jogadaPJ;

        if (jogadaPJ == 1 || jogadaPJ == 2) { //Verifica se o jogador digitou os números corretos.

            system("cls");
            setColor(10); 
            cout << "Você escolheu: " << jogadaPJ << "\n"; 
            setColor(11); 
            cout << "Jogador 2 escolheu: " << jogadores[0] << "\n"; 
            cout << "Jogador 3 escolheu: " << jogadores[1] << "\n\n"; 
            
            if ((jogadaPJ == jogadores[0]) && (jogadaPJ == jogadores[1])) { //Verifica se houve um empate entre os jogadores.

                setColor(14); 
                cout << "Resultado: EMPATE!\n\n";
                setColor(15); 
                cout << "Jogar novamente? ";
                system("pause");
                system("cls");
                continue;

            } else if (jogadaPJ == jogadores[0]) {

                setColor(10); 
                cout << "Resultado: VITÓRIA!\n";
                setColor(12); 
                cout << "Jogador 3 perdeu a rodada.\n\n";
                setColor(15); 
                cout << "Prosseguir para próxima etapa? ";
                system("pause");
                system("cls");
                primeiraVitoria = true;

            } else if (jogadaPJ == jogadores[1]) {

                setColor(10); 
                cout << "Resultado: VITÓRIA!\n";
                setColor(12); 
                cout << "Jogador 2 perdeu a rodada.\n\n";
                setColor(15); 
                cout << "Prosseguir para próxima etapa? ";
                system("pause");
                system("cls");
                primeiraVitoria = true;

            } else { //Caso não tenha empate, então você perdeu.

                setColor(12); 
                cout << "Resultado: DERROTA!\n\n";
                setColor(15); 
                cout << "Jogar novamente? ";
                system("pause");
                system("cls");
                continue;

            }
        } else {
            system("cls");
            continue;
        }

    //Jogo de Par ou Impar.
    } while (!primeiraVitoria); //Declara o fim do loop quando primeiraVitoria for declarado TRUE.

    system("cls");
    
    do {

        jogadaPJ = 0;
        jogadores[0] = rand() % 10 + 1; //Define um número aleatorio de até 10.
        setColor(15); 
        cout << "Par ou Impar!\n\n";
        setColor(14); 
        cout << "[1] Escolher Par\n";
        cout << "[2] Escolher Impar\n";
        cin >> escolhaPJ;

        system("cls");
        setColor(15);
        cout << "Digite o número que vai ser jogado (No máximo até 10): ";
        cin >> jogadaPJ;
        system("cls");

        if ((escolhaPJ == 1 || escolhaPJ == 2) && (jogadaPJ >= 1 && jogadaPJ <= 10)) { //Verifica se os requisitos foram atendidos corretamente.

            int somaJogadas = jogadaPJ + jogadores[0];
            bool parImpar = somaJogadas % 2 == 0; //Ve se o resto foi 0 e define se é impar ou par.
            setColor(11); 
            cout << "Você escolheu: " << jogadaPJ << "\n";
            setColor(14); 
            cout << "Outro jogador escolheu: " << jogadores[0] << "\n";
            cout << "Soma das jogadas: " << somaJogadas << "\n\n";

            setColor(11);
            cout << "Prosseguir para os resultados? \n";
            setColor(15);
            system("pause");

            if ((parImpar && escolhaPJ == 1) || (!parImpar && escolhaPJ == 2)) { //Verficia se voltou true ou false e de acordo com a escolha do jogador.

                system("cls");
                segundaVitoria = true;

            } else {
                setColor(12);
                cout << "Resultado: DERROTA!\n\n";
                setColor(14); 
                cout << "Jogar novamente? ";
                system("pause");
                system("cls");
                continue; 
            }
        } else {
            system("cls");
            continue;
        }

    } while (!segundaVitoria);

    //Mensagem de vitória.
    setColor(10);
    cout << "Parabéns!\n";
    cout << "Você ganhou os dois jogos, aqui está seu grande prêmio: \n\n";

    for (int k = 0; k < 9; k++) {
        setColor(14);
        cout << trofeu[k] << endl;
        Sleep(200);
    }

    system("pause");
    return 0;
}
