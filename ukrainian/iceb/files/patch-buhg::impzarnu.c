diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/impzarnu.c work/buhg/impzarnu.c
--- work.old/buhg/impzarnu.c	Thu Jan 16 00:07:53 2003
+++ buhg/impzarnu.c	Tue Jan 21 21:42:50 2003
@@ -94,7 +94,7 @@
  {
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_8_1_2.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_8_1_2.txt");
     prosf(strsql);
     clear();
     goto naz;
