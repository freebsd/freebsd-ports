diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dvuslf2.c work/buhg/dvuslf2.c
--- work.old/buhg/dvuslf2.c	Thu Jan 16 00:07:52 2003
+++ buhg/dvuslf2.c	Tue Jan 21 21:42:50 2003
@@ -129,7 +129,7 @@
   case FK1:
     GDITE();
 
-    sprintf(bros,"%s/doc/%s",putnansi,"usl4_1.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"usl4_1.txt");
     prosf(bros);
 
     clear();
