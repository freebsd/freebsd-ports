diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/doocsum.c work/buhg/doocsum.c
--- work.old/buhg/doocsum.c	Thu Jan 16 00:07:52 2003
+++ buhg/doocsum.c	Tue Jan 21 21:42:50 2003
@@ -66,7 +66,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu5_16.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_16.txt");
     prosf(bros);
     clear();
     goto naz1;
