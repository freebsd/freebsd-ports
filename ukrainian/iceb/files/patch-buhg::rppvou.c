diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rppvou.c work/buhg/rppvou.c
--- work.old/buhg/rppvou.c	Thu Jan 16 00:07:58 2003
+++ buhg/rppvou.c	Tue Jan 21 21:42:52 2003
@@ -84,7 +84,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"usl4_3.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"usl4_3.txt");
     prosf(bros);
     clear();
     goto naz;
