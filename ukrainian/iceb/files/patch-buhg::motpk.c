diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/motpk.c work/buhg/motpk.c
--- work.old/buhg/motpk.c	Thu Jan 16 00:07:54 2003
+++ buhg/motpk.c	Tue Jan 21 21:42:51 2003
@@ -170,7 +170,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu5_6.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_6.txt");
     prosf(bros);
     clear();
     goto naz;
