diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasnds.c work/buhg/rasnds.c
--- work.old/buhg/rasnds.c	Thu Jan 16 00:07:56 2003
+++ buhg/rasnds.c	Tue Jan 21 21:42:51 2003
@@ -139,7 +139,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu5_10.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_10.txt");
     prosf(bros);
     clear();
     goto naz;
