diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarsprpr.c work/buhg/zarsprpr.c
--- work.old/buhg/zarsprpr.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarsprpr.c	Tue Jan 21 21:42:54 2003
@@ -138,7 +138,7 @@
  {
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_2.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_2.txt");
     prosf(strsql);
     goto naz;
 
