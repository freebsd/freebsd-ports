diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/printpershek.c work/buhg/printpershek.c
--- work.old/buhg/printpershek.c	Thu Jan 16 00:07:55 2003
+++ buhg/printpershek.c	Tue Jan 21 21:42:51 2003
@@ -44,7 +44,7 @@
 /*
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"buhg3_2.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg3_2.txt");
     prosf(strsql);
     clear();
     goto naz1;
