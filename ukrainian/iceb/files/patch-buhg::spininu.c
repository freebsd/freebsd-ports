diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/spininu.c work/buhg/spininu.c
--- work.old/buhg/spininu.c	Thu Jan 16 00:07:58 2003
+++ buhg/spininu.c	Tue Jan 21 21:42:52 2003
@@ -88,7 +88,7 @@
 
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_4.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_4.txt");
     prosf(strsql);
     goto naz;
 
