diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirdok.c work/buhg/dirdok.c
--- work.old/buhg/dirdok.c	Thu Jan 16 00:07:50 2003
+++ buhg/dirdok.c	Tue Jan 21 21:42:49 2003
@@ -547,7 +547,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
