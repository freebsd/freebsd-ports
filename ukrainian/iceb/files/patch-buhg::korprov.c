--- buhg/korprov.c.orig	Wed Oct  8 19:52:09 2003
+++ buhg/korprov.c	Wed Oct  8 19:52:22 2003
@@ -19,7 +19,7 @@
 char sh[],  //Счет
 char shk[], //Счет корреспондент
 char kor[], //Код контрагента
-long vrem,  //время записи
+time_t vrem,  //время записи
 int ktoi,
 char kto[])
 {
@@ -36,7 +36,7 @@
 struct  tm      *bf;
 int             par;
 char            bros1[100];
-long            tmm;
+time_t            tmm;
 struct OPSHET	shetv;
 struct OPSHET	shetv1;
 
