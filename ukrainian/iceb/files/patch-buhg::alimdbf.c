diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/alimdbf.c work/buhg/alimdbf.c
--- work.old/buhg/alimdbf.c	Thu Jan 16 00:08:26 2003
+++ buhg/alimdbf.c	Tue Jan 21 21:42:49 2003
@@ -96,7 +96,7 @@
 
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_4_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_4_1.txt");
     prosf(strsql);
     goto naz;
 
