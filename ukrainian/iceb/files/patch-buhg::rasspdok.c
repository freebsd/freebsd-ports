diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasspdok.c work/buhg/rasspdok.c
--- work.old/buhg/rasspdok.c	Thu Jan 16 00:07:57 2003
+++ buhg/rasspdok.c	Tue Jan 21 21:42:51 2003
@@ -127,7 +127,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu5_8.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_8.txt");
     prosf(bros);
     clear();
     goto naz;
