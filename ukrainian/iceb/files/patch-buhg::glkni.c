--- buhg/glkni.c.orig	Thu Aug 29 08:36:23 2002
+++ buhg/glkni.c	Wed Oct  8 19:49:47 2003
@@ -51,9 +51,9 @@
 {
 int		metkarash=0;
 char            bros[100];
-long            tmm;
-long            tmmn;
-long            tmmk;
+time_t            tmm;
+time_t            tmmn;
+time_t            tmmk;
 int             i,kom,sb;
 char            sh[20];
 char            imaf[20],imatab[20],imaf3[20];
@@ -99,7 +99,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"buhg5_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg5_1.txt");
    prosf(strsql);
    goto naz;
 
