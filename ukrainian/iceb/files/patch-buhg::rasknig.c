diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasknig.c work/buhg/rasknig.c
--- work.old/buhg/rasknig.c	Thu Jan 16 00:07:56 2003
+++ buhg/rasknig.c	Tue Jan 21 21:42:51 2003
@@ -91,7 +91,7 @@
  {
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu5_14.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_14.txt");
     prosf(bros);
     clear();
     goto nazz;
