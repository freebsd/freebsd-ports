diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/pld.c work/buhg/pld.c
--- work.old/buhg/pld.c	Thu Jan 16 00:07:55 2003
+++ buhg/pld.c	Tue Jan 21 21:42:51 2003
@@ -352,7 +352,7 @@
 
   case FK1:   /*Помощь*/
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"dokum2_1_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"dokum2_1_1.txt");
     prosf(strsql);
     clear();
     goto naz;
