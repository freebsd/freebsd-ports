--- buhg/xbu.c.orig	Mon Sep  9 01:38:02 2002
+++ buhg/xbu.c	Wed Oct  8 19:08:40 2003
@@ -57,7 +57,7 @@
 int             i;
 char            bros1[200];
 struct  tm      *bf;
-long            tmm;
+time_t            tmm;
 char		kto[20];
 char		host[100];
 char		*parol=NULL;
@@ -317,7 +317,7 @@
           goto nazad;
         case FK1:
           GDITE();
-          sprintf(strsql,"%s/doc/%s",putnansi,"buhg3_2.txt");
+          sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg3_2.txt");
           prosf(strsql);
           clear();
           goto naz1;
@@ -478,7 +478,7 @@
        {
         case FK1:   /*Помощь*/
          GDITE();
-         sprintf(bros,"%s/doc/%s",putnansi,"buhg5_2.txt");
+         sprintf(bros,"%s/%s",ICEB_DOC_PATH,"buhg5_2.txt");
          prosf(bros);
          goto naz;
        
@@ -609,7 +609,7 @@
 
         case FK1:
           GDITE();
-          sprintf(bros,"%s/doc/%s",putnansi,"buhg5_4.txt");
+          sprintf(bros,"%s/%s",ICEB_DOC_PATH,"buhg5_4.txt");
           prosf(bros);
           goto nom3;
 
