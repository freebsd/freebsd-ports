diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarsr.c work/buhg/zarsr.c
--- work.old/buhg/zarsr.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarsr.c	Tue Jan 21 21:42:54 2003
@@ -73,7 +73,7 @@
 
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_11.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_11.txt");
     prosf(strsql);
     goto naz;
 
