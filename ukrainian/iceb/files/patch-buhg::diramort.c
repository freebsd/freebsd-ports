diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/diramort.c work/buhg/diramort.c
--- work.old/buhg/diramort.c	Thu Jan 16 00:07:50 2003
+++ buhg/diramort.c	Tue Jan 21 21:42:49 2003
@@ -244,7 +244,7 @@
 
   case FK1: /*помощь*/
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"uos8.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"uos8.txt");
     prosf(strsql);
     clear();
     goto naz1;
