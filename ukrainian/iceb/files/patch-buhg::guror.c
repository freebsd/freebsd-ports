--- buhg/guror.c.orig	Wed Oct  8 19:50:00 2003
+++ buhg/guror.c	Wed Oct  8 19:50:25 2003
@@ -42,7 +42,7 @@
 short		klzvk;      /*Количество знаков в колонке*/
 short           klsh;       /*Количество счетов по горизонтали*/
 struct  tm      *bf;
-long            tmm,tmmk,tmmn;
+time_t            tmm,tmmk,tmmn;
 double          sd,sk,sdn,skn;
 char            imaf[20];
 short           m,g;
@@ -624,7 +624,7 @@
 short           i;
 char            sh[40];
 struct  tm      *bf;
-long            tmm;
+time_t            tmm;
 char		polka[20];
 
 memset(polka,'\0',sizeof(polka));
