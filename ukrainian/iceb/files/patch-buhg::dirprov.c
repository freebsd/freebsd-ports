--- buhg/dirprov.c.orig	Mon Sep  9 01:38:02 2002
+++ buhg/dirprov.c	Wed Oct  8 19:33:00 2003
@@ -349,7 +349,7 @@
 
   case FK1:
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"buhg3a.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"buhg3a.txt");
    prosf(bros);
    clear();
    goto naz;
@@ -823,7 +823,7 @@
 {
 short		d,m,g;
 struct  tm      *bf;
-long		tmm;
+time_t		tmm;
 char		strsql[300];
 SQL_str		row1;
 
