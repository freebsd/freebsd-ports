--- buhg/impprov.c.orig	Mon Jul 29 10:28:37 2002
+++ buhg/impprov.c	Wed Oct  8 19:52:01 2003
@@ -60,7 +60,7 @@
  {
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/buhg3_5.txt",putnansi);
+    sprintf(strsql,"%s/buhg3_5.txt",ICEB_DOC_PATH);
     prosf(strsql);
     clear();
     goto naz;
@@ -135,7 +135,7 @@
 char  shetk[30];
 char  kontrsh[30];
 char  kontrshk[30];
-long  vrem;
+time_t  vrem;
 double  deb=0.,kre=0.;
 char	koment[200];
 
