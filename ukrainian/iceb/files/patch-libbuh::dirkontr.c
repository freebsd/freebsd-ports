--- libbuh/dirkontr.c.orig	Mon Sep  2 08:00:29 2002
+++ libbuh/dirkontr.c	Wed Oct  8 18:54:17 2003
@@ -31,7 +31,7 @@
 char            nnn[40];
 extern char     *organ;
 struct  tm      *bf;
-long            tmm;
+time_t          tmm;
 short           x=0,y=2;
 int             K;
 int             kom;
@@ -395,7 +395,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"buhg4_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg4_2.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
@@ -925,7 +925,7 @@
 FILE		*ff;
 char		strsql[300];
 struct  tm      *bf;
-long            tmm;
+time_t            tmm;
 char		imatab[30];
 
 VVOD DANET(1);
