--- libbuh/dirskont.c.orig	Mon Sep  2 08:00:29 2002
+++ libbuh/dirskont.c	Wed Oct  8 18:58:30 2003
@@ -35,8 +35,8 @@
 extern char	*putnansi;
 char            bros[100];
 short           x=0,y=2;  /*Позиция вывода списка*/
-long            tmm;
-long            tmmk;
+time_t            tmm;
+time_t            tmmk;
 int             i,i1;
 int             kom;
 int             K,kl;
@@ -63,7 +63,7 @@
 long		pozz,pozz1;
 SQL_str         row,row1;
 char		strsql[300];
-long		vr;
+time_t		vr;
 char		kodvk[30];
 short		mspz; /*метка соответствия первой записи*/
 short		metpoi;
@@ -565,7 +565,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"buhg4_3.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg4_3.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
@@ -1192,7 +1192,7 @@
 FILE		*ff;
 char		strsql[300];
 struct  tm      *bf;
-long            tmm;
+time_t            tmm;
 char		bros[100];
 char		imatab[30];
 
