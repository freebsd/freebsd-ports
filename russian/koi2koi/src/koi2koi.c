#include <stdio.h>
#include "algoreco.h"


#define from_encoding koi
#define to_encoding koi
#define message_encoding koi
#define max_buffer_size 512

unsigned char buffer[max_buffer_size],debugchar[2];
unsigned int lastchar, newchar, j, n, code_num;
int i, statist[5];


#define from_to_char(argf,argt,argd) \
                ( argd < 128 )? argd :\
                (( argf ==iso)&&( argt ==iso))?  argd :\
                ( argf ==iso)? to_the [ argt ][ argd & 127 ] :\
                ( argt ==iso)? from_the [ argf ][ argd & 127 ] :\
         to_the [ argt ][(from_the [ argf ][ argd & 127]) & 127 ]

#define from_char(argf,argd) ((argd<128)||(argf==iso))? argd :\
                             from_the [argf][argd & 127]

int biletter_index (int encoding, int last_char, int new_char)
{
   int new;
   new=key_new[from_char(encoding,new_char)];
   new=(table[key_last[from_char(encoding,last_char)]][new>>2]>>((new & 3)<<1))&3;
   if (new==3) new=-10;
   return(new);
}

int main()
{
  while (((newchar=getchar())!=EOF)&&( newchar<128))
  {
    putchar(newchar);
    lastchar=newchar;
  }
  n=0;
        j=0;
  /* Пропустив возможное латинское начало */
  while ((n<max_buffer_size)&&(newchar!=EOF))
  {
    /* проверяем на кодировку from_encoding входной текст, сохраняя на
     * всякий случай его в буфере
     */
    buffer[n++]=newchar;
    i=biletter_index(from_encoding,lastchar,newchar);
#if defined debug
                debugchar[0]=from_to_char(from_encoding,message_encoding,lastchar);
                debugchar[1]=from_to_char(from_encoding,message_encoding,newchar);
                printf("%.1s%d%.1s{[%d,%d]->[%d,%d]->[%d,%d]->%d>>%d(%d)}\n",
                debugchar, i,debugchar+1,
                lastchar,newchar,
                from_char(from_encoding,lastchar), from_char(from_encoding,newchar),
                key_last[from_char(from_encoding,lastchar)],
                key_new[from_char(from_encoding,newchar)],
                table[key_last[from_char(from_encoding,lastchar)]]
                [key_new[from_char(from_encoding,newchar)]>>2],
                (key_new[from_char(from_encoding,newchar)]&3)<<1,
                from_encoding);
#endif
    if (newchar>128)
    {
      j=(i==0)? j+2:
        (i==1)? j++:
        (i==2)? 0:5;
      if (j>3)
      {
#if defined debug
        printf("Подозрительно похоже на бессмыслицу!\n");
#endif
        break;
      }
    }
    lastchar=newchar;
    newchar=getchar();
  }
    /* Если нет особых оснований сомневаться в кои - заканчиваем;
     *
     */
  if ((n==max_buffer_size)||(newchar==EOF))
    {
      for(i=0;i<n;i++)
      {
        putchar( from_to_char ( from_encoding, to_encoding, (buffer[i]) ) );
      }
      while ((newchar)!=EOF)
      {
        putchar(newchar);
        newchar=getchar();
      }
      exit (0);
    }
    /* Если есть сомнения, выясняем правильную кодировку;
     * Сначала добавляем материал для статистики.
     */
    while ((n!=max_buffer_size)&&((newchar=getchar())!=EOF))
    {
      buffer[n++]=newchar;
    }
    lastchar=' ';
    for(j=0;j<5;j++)
    {
#if defined debug
      printf("Набираем статистику для кодировки номер %d:\n",j);
#endif
      statist[j]=0;
      lastchar=' ';
      for (i=0;i<n;i++)
      {
#if defined debug
        char debg[2]="  ";
        int q,r,b;
#endif
        newchar=buffer[i];
        statist[j]+=
                biletter_index(j,lastchar,newchar);
#if defined debug
                debg[0]=from_to_char(j, message_encoding, lastchar);
                printf("%.1s", debg);
                if(biletter_index(j,lastchar,newchar))
                printf("%d", biletter_index(j,lastchar,newchar));
#endif
        lastchar=newchar;
      }
#if defined debug
    printf("Индекс кодировки %d равен %d.\n",j,statist[j]);
#endif
    }
    /* Осталось определить победителя
     */
    code_num=from_encoding;
                for(i=0;i<5;i++)
                {
      if (statist[i] > statist[code_num]) code_num=i;
                }
#if defined debug
     printf("Кодировка файла= %d.\n",code_num);
#endif
    /* и завершить работу
     */
    for(i=0;i<n;i++)
    {
      putchar( from_to_char ( code_num, to_encoding, (buffer[i]) ) );
    }
    while ((newchar=getchar())!=EOF)
    {
      putchar(from_to_char(code_num, to_encoding, newchar));
    }
    return 0;
}


