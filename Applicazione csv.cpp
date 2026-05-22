#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Location {
    double Lat;
    double Lon; 
};

struct zoneBG {
    string ClasseToponimo;
    string DescrizioneToponimo;
    string Numero;
    string Subalterno;
    int CAP;
    int SezioneISTAT;
    Location posto;
};

void inserimento(){
ifstream fileInput("Comune_Bergamo_-_Numerazione_civica"); 
    string linea;

    if (fileInput.is_open()) {
        while (getline(fileInput, linea)){
            i++;
        }
        
        fileInput.close();
    } else {
        cout << "Impossibile aprire il file";
    }

}

int main(int argc, char** argv) {
    
	do {
    	cout<<endl;
        cout<<"1 - (C)Carica dati"<<endl;
        cout<<"2 - (R)Visualizzazione"<<endl;
        cout<<"3 - (V)Inserisci via"<<endl;
        cout<<"0 - Fine programma"<<endl;
        cout<<"Scegli l'opzione: ";
        cin>>scelta;

        switch(scelta) {
            case 1:
                cout<<"Inserisci il numero di righe che vuoi salvare ";
                cin>>n;
                if(n>MAX_RIGHE) 
				n = MAX_RIGHE;
                
                carica_dati(n, elenco, resto);
                
                if (resto == -1) {
                    cout << "file non trovato"<<endl;
                    n = 0;
                } else {
                    n = resto;
                }
                break;
            case 2: 
                if (n <= 0) {
                    cout<<"carica prima i dati."<<endl;
                } else {
                    cout<<visualizza(n,elenco);
                }
                break;   
            case 3:{
    		if (n <= 0) {
       			cout << "Carica prima i dati"<<endl;
        		break;
    		} string via;
    		cout << "Inserisci la via da cercare: ";
    		//attenzone, inserire la via che si vuole escludendo la parola VIA e replicando perfettamente il testo
    		// es se io voglio VIA ARENA, digito solo ARENA
    		cin.ignore(10000, '\n');
    		getline(cin, via);
    		ordina_via(elenco, n, via);
    		}
           // case 0:
            //    break;
        }
    } while (scelta != 0);
    return 0;
}
//{}