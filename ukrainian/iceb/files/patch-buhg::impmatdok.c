diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/impmatdok.c work/buhg/impmatdok.c
--- work.old/buhg/impmatdok.c	Thu Jan 16 00:07:53 2003
+++ buhg/impmatdok.c	Tue Jan 21 21:42:50 2003
@@ -79,7 +79,7 @@
  {
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"matu2_5.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_5.txt");
     prosf(strsql);
     clear();
     goto naz;
