diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirdok1.c work/buhg/dirdok1.c
--- work.old/buhg/dirdok1.c	Thu Jan 16 00:07:50 2003
+++ buhg/dirdok1.c	Tue Jan 21 21:42:49 2003
@@ -534,7 +534,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
