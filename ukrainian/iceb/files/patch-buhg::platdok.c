diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/platdok.c work/buhg/platdok.c
--- work.old/buhg/platdok.c	Thu Jan 16 00:07:55 2003
+++ buhg/platdok.c	Tue Jan 21 21:42:51 2003
@@ -477,7 +477,7 @@
 
     case FK1:   /*Помощь*/
       GDITE();
-      sprintf(strsql,"%s/doc/%s",putnansi,"dokum2_1.txt");
+      sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"dokum2_1.txt");
       prosf(strsql);
       clear();
       par=0;
