--- libbuh/dirshet.c.orig	Mon Aug 26 03:46:09 2002
+++ libbuh/dirshet.c	Wed Oct  8 18:54:57 2003
@@ -30,7 +30,7 @@
 {
 int             x=0,y=2;  /*Позиция вывода списка*/
 struct  tm      *bf;
-long            tmm;
+time_t          tmm;
 char            na[50]; /*Наименование счета*/
 int             tipsh; /*Тип счета*/
 int             vidsh; /*Вид счета*/
@@ -328,7 +328,7 @@
   case FK1:   /*Получить подсказку*/
    
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"buhg4_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg4_1.txt");
    prosf(strsql);
    clear();
    goto naz;
@@ -538,7 +538,7 @@
 short           mt;
 char		shz[20];
 short		nm=3;
-long		vrem;
+time_t		vrem;
 //char		ST[90];
 char		bros[100];
 int		kl,dan;
