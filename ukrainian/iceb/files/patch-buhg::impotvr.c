diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/impotvr.c work/buhg/impotvr.c
--- work.old/buhg/impotvr.c	Thu Jan 16 00:07:53 2003
+++ buhg/impotvr.c	Tue Jan 21 21:42:50 2003
@@ -64,7 +64,7 @@
  {
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_6_2.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_6_2.txt");
     prosf(strsql);
     clear();
     goto naz;
