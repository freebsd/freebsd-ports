--- buhg/dvtmcf1.c.orig	Fri Sep  6 01:23:08 2002
+++ buhg/dvtmcf1.c	Wed Oct  8 20:03:24 2003
@@ -44,9 +44,9 @@
 char            str1[300];
 extern char	*maskmat; /*Массив кодов отмеченных материалов*/
 struct  tm      *bf;
-long            tmm;
-long            tmmn;
-long            tmmk;
+time_t            tmm;
+time_t            tmmn;
+time_t            tmmk;
 short           kst,sli;
 char            imaf[20],imaftmp[20],imafkl2[30],imafuz[30];
 short           dn,mn,gn;
@@ -199,9 +199,9 @@
   case FK1:
     GDITE();
     if(tipras == 0)
-      sprintf(bros,"%s/doc/%s",putnansi,"matu5_4.txt");
+      sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_4.txt");
     if(tipras == 1)
-      sprintf(bros,"%s/doc/%s",putnansi,"matu5_7.txt");
+      sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_7.txt");
     prosf(bros);
     clear();
     goto naz;
