diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/mariq.c work/buhg/mariq.c
--- work.old/buhg/mariq.c	Thu Jan 16 00:07:53 2003
+++ buhg/mariq.c	Tue Jan 21 21:42:51 2003
@@ -589,7 +589,7 @@
 /*
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"buhg3_2.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg3_2.txt");
     prosf(strsql);
     clear();
     goto naz1;
@@ -656,7 +656,7 @@
 /*
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"buhg3_2.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg3_2.txt");
     prosf(strsql);
     clear();
     goto naz1;
