diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasspdoku.c work/buhg/rasspdoku.c
--- work.old/buhg/rasspdoku.c	Thu Jan 16 00:07:57 2003
+++ buhg/rasspdoku.c	Tue Jan 21 21:42:51 2003
@@ -120,7 +120,7 @@
   case FK1:
     GDITE();
 
-    sprintf(bros,"%s/doc/%s",putnansi,"usl4_2.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"usl4_2.txt");
     prosf(bros);
 
     clear();
