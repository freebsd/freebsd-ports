diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarsend.c work/buhg/zarsend.c
--- work.old/buhg/zarsend.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarsend.c	Tue Jan 21 21:42:54 2003
@@ -141,7 +141,7 @@
 
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_1_3.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_1_3.txt");
     prosf(strsql);
     goto naz;
 
