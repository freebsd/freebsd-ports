diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/spiin.c work/buhg/spiin.c
--- work.old/buhg/spiin.c	Thu Jan 16 00:07:58 2003
+++ buhg/spiin.c	Tue Jan 21 21:42:52 2003
@@ -104,7 +104,7 @@
 
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_3.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_3.txt");
     prosf(strsql);
     goto naz;
 
