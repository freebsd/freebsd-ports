diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/srvcen.c work/buhg/srvcen.c
--- work.old/buhg/srvcen.c	Thu Jan 16 00:07:59 2003
+++ buhg/srvcen.c	Tue Jan 21 21:42:52 2003
@@ -79,7 +79,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu2_4.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu2_4.txt");
     prosf(bros);
     clear();
     goto naz;
