diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dvtmcf2.c work/buhg/dvtmcf2.c
--- work.old/buhg/dvtmcf2.c	Thu Jan 16 00:07:52 2003
+++ buhg/dvtmcf2.c	Tue Jan 21 21:42:50 2003
@@ -143,7 +143,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu5_5.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_5.txt");
     prosf(bros);
     clear();
     goto naz;
