--- buhg/dirmatr.c.orig	Mon Sep  2 07:18:24 2002
+++ buhg/dirmatr.c	Wed Oct  8 19:58:47 2003
@@ -41,7 +41,7 @@
 double		kolih;
 short           x=0,y=4;
 struct  tm      *bf;
-long            tmm;
+time_t            tmm;
 int             K;
 int             kom,kom1;
 int             i,prc;
@@ -527,7 +527,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu4_3.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu4_3.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
@@ -941,7 +941,7 @@
 int kodg, //Код группы материала
 char ei[], //Единица измерения
 int kt, //Кто записал
-long vr, //Время записи
+time_t vr, //Время записи
 int mk, //0- ввод нового 1 - корректировка
 float nds) //0-цена с НДС 1-цена без НДС
 {
@@ -958,7 +958,7 @@
 char		bros[100];
 char		ST[100];
 int		ktoi;
-long		vrem;
+time_t		vrem;
 char		strsql[500];
 SQL_str         row;
 int		poz,komv;
@@ -1273,7 +1273,7 @@
     attroff(VV->VVOD_return_cs(iceb_CFS));
     attron(VV->VVOD_return_cs(iceb_CFM));
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"matu4_3_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu4_3_1.txt");
     prosf(strsql);
     clear();
     goto naz;
@@ -1561,7 +1561,7 @@
 short		kp;
 short		i;
 char		kodm[12];
-long		tmm;
+time_t		tmm;
 struct  tm      *bf;
 SQL_str         row;
 char		strsql[200];
@@ -1735,7 +1735,7 @@
 FILE		*ff;
 char		strsql[300];
 struct  tm      *bf;
-long            tmm;
+time_t            tmm;
 char		imatab[30];
 
 VVOD DANET(1);
