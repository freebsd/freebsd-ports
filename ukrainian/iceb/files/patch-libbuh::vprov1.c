--- libbuh/vprov1.c.orig	Wed Oct  8 18:57:11 2003
+++ libbuh/vprov1.c	Wed Oct  8 18:57:37 2003
@@ -24,7 +24,7 @@
 int skk,   //Код подразделения
 int d,int m,int g, //Дата документа
 short mt, //0-ввод 1-корректировка
-long vremz, //Время записи корректируемой проводки
+time_t vremz, //Время записи корректируемой проводки
 char kontr[], //Код контрагента для корректируемой проводки если он есть
 int  ktozap,  //Кто записал
 char mtsh[], //Перечень материальных счетов
@@ -35,7 +35,7 @@
 {
 struct  tm      *bf;
 struct  passwd  *ktoz; /*Кто записал*/
-long		vrem;
+time_t		vrem;
 int             KLST,MDLS;
 int             dlr;
 short           i,PR,K;
