diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/copdoku.c work/buhg/copdoku.c
--- work.old/buhg/copdoku.c	Thu Jan 16 00:07:50 2003
+++ buhg/copdoku.c	Tue Jan 21 21:42:49 2003
@@ -94,7 +94,7 @@
   case FK1:   /*Помощь*/
    GDITE();
 /*
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2d.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2d.txt");
    prosf(strsql);
    clear();
 */
