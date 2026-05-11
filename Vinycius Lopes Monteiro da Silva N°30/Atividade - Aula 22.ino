//  Atividade - Aula 22: Introdução ao Arduino no Tinkercad
//  AlunoS: Vinycius Lopes, Vinicius dos Santos, Tainá Silveira 
//  Disciplina: Desenvolvimento de Sistemas - SENAI

// Declaração das portas dos LEDs
// Cada variável armazena o número da porta digital onde o LED está conectado.
// Porta digital = pino físico do Arduino que envia sinal elétrico (0V ou 5V).

int portLed1 = 10;  // LED 1 - vermelho
int portLed2 = 9;   // LED 2 - amarelo
int portLed3 = 8;   // LED 3 - verde

// Declaração dos tempos de delay em milissegundos
int velocidadeLenta  = 1000;  // 1 segundo  (pisca devagar)
int velocidadeMedia  = 500;   // 0,5 segundo (pisca médio)
int velocidadeRapida = 150;   // 0,15 segundo (pisca rápido)


//  void setup()
//  Executado UMA vez quando o Arduino é ligado ou resetado.
//  Aqui configuramos as portas como saída (OUTPUT),
//  ou seja, o Arduino vai ENVIAR sinal elétrico por elas.

void setup()
{
  // pinMode(pino, modo)
  // Define se a porta vai enviar (OUTPUT) ou receber (INPUT) sinal.
  // Como controlamos LEDs, usamos OUTPUT em todas.
  pinMode(portLed1, OUTPUT);
  pinMode(portLed2, OUTPUT);
  pinMode(portLed3, OUTPUT);
}

//  void loop()
void loop()
{

  // LED 1 piscando em velocidade LENTA (1s)
  
  // digitalWrite(pino, valor)
  // Envia sinal para a porta.
  // HIGH = 5 volts → LED acende
  // LOW  = 0 volts → LED apaga
  digitalWrite(portLed1, HIGH);   // Acende LED 1
  delay(velocidadeLenta);         // Espera 1000ms (1 segundo)
  digitalWrite(portLed1, LOW);    // Apaga LED 1
  delay(velocidadeLenta);         // Espera 1000ms

  //  PARTE 2 - LED 2 piscando em velocidade MÉDIA (500ms)
  
  digitalWrite(portLed2, HIGH);   // Acende LED 2
  delay(velocidadeMedia);         // Espera 500ms
  digitalWrite(portLed2, LOW);    // Apaga LED 2
  delay(velocidadeMedia);         // Espera 500ms

 
  // LED 3 piscando em velocidade RÁPIDA (150ms)
  // Repete 5 vezes para dar efeito de "flash rápido"
  
  for (int i = 0; i < 5; i++) {
    digitalWrite(portLed3, HIGH); // Acende LED 3
    delay(velocidadeRapida);      // Espera 150ms
    digitalWrite(portLed3, LOW);  // Apaga LED 3
    delay(velocidadeRapida);      // Espera 150ms
  }

  //  SEQUÊNCIA DE ILUMINAÇÃO
  //  LED 1 → LED 2 → LED 3 → LED 2 → LED 1
  
  digitalWrite(portLed1, HIGH);  delay(400);
  digitalWrite(portLed1, LOW);

  digitalWrite(portLed2, HIGH);  delay(400);
  digitalWrite(portLed2, LOW);

  digitalWrite(portLed3, HIGH);  delay(400);
  digitalWrite(portLed3, LOW);

  digitalWrite(portLed2, HIGH);  delay(400);
  digitalWrite(portLed2, LOW);

  digitalWrite(portLed1, HIGH);  delay(400);
  digitalWrite(portLed1, LOW);

  //  Todos os LEDs acendem juntos e apagam juntos
  
  digitalWrite(portLed1, HIGH);
  digitalWrite(portLed2, HIGH);
  digitalWrite(portLed3, HIGH);
  delay(800);

  digitalWrite(portLed1, LOW);
  digitalWrite(portLed2, LOW);
  digitalWrite(portLed3, LOW);
  delay(800);
}