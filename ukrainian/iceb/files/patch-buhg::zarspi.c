diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarspi.c work/buhg/zarspi.c
--- work.old/buhg/zarspi.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarspi.c	Tue Jan 21 21:42:54 2003
@@ -98,7 +98,7 @@
 
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_1_2.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_1_2.txt");
     prosf(strsql);
     goto naz;
 
