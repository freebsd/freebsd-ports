diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dooc.c work/buhg/dooc.c
--- work.old/buhg/dooc.c	Thu Jan 16 00:07:52 2003
+++ buhg/dooc.c	Tue Jan 21 21:42:50 2003
@@ -69,7 +69,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu2_1_2h.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu2_1_2h.txt");
     prosf(bros);
     clear();
     goto naz1;
