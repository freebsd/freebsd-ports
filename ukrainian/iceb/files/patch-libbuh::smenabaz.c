diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/libbuh/smenabaz.c work/libbuh/smenabaz.c
--- work.old/libbuh/smenabaz.c	Thu Jan 16 00:07:28 2003
+++ libbuh/smenabaz.c	Tue Jan 21 22:24:22 2003
@@ -42,7 +42,7 @@
   if(i == FK1)
    {
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"smenabaz.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"smenabaz.txt");
     prosf(strsql);
     clear();
     goto naz;
