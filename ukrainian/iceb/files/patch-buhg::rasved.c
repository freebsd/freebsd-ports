diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasved.c work/buhg/rasved.c
--- work.old/buhg/rasved.c	Thu Jan 16 00:07:57 2003
+++ buhg/rasved.c	Tue Jan 21 21:42:51 2003
@@ -171,7 +171,7 @@
 
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_1_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_1_1.txt");
     prosf(strsql);
     goto naz;
 
