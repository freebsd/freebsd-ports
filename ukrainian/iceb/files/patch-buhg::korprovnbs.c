--- buhg/korprovnbs.c.orig	Wed Oct  8 19:52:40 2003
+++ buhg/korprovnbs.c	Wed Oct  8 19:52:45 2003
@@ -18,7 +18,7 @@
 void            korprovnbs(VVOD *VV,short d,short m,short g, //Дата
 char sh[],  //Счет
 char kor[], //Код контрагента
-long vrem,  //время записи
+time_t vrem,  //время записи
 int ktoi,
 char kto[])
 {
