--- buhg/salallk.c.orig	Wed Sep  4 02:52:01 2002
+++ buhg/salallk.c	Wed Oct  8 19:54:43 2003
@@ -45,7 +45,7 @@
 short           dk,mk,gk;
 int             i;
 char            sh[10];
-long            tmm;
+time_t            tmm;
 struct  tm      *bf;
 long		kolstr;
 SQL_str         row;
@@ -99,7 +99,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"buhg5_3.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg5_3.txt");
    prosf(strsql);
    clear();
    goto naz;
@@ -268,8 +268,8 @@
 long		kolstr,kolstr1;
 SQL_str         row,row1;
 char		strsql[300];
-long            tmm;
-long            tmmk;
+time_t            tmm;
+time_t            tmmk;
 struct  tm      *bf;
 short		mro,mrodeb,mrokre;
 char		imaf[30],imaf1[30],imafdeb[30],imafkre[30];
