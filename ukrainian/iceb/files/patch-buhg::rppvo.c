diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rppvo.c work/buhg/rppvo.c
--- work.old/buhg/rppvo.c	Thu Jan 16 00:07:58 2003
+++ buhg/rppvo.c	Tue Jan 21 21:42:52 2003
@@ -90,7 +90,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu5_9.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_9.txt");
     prosf(bros);
     clear();
     goto naz;
