diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/prognoz.c work/buhg/prognoz.c
--- work.old/buhg/prognoz.c	Thu Jan 16 00:07:55 2003
+++ buhg/prognoz.c	Tue Jan 21 21:42:51 2003
@@ -98,7 +98,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu5_11.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_11.txt");
     prosf(bros);
     clear();
     goto naz;
