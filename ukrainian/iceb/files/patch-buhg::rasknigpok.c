diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasknigpok.c work/buhg/rasknigpok.c
--- work.old/buhg/rasknigpok.c	Thu Jan 16 00:07:56 2003
+++ buhg/rasknigpok.c	Tue Jan 21 21:42:51 2003
@@ -81,7 +81,7 @@
  {
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu5_15.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_15.txt");
     prosf(bros);
     clear();
     goto nazz;
