diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirmatr1.c work/buhg/dirmatr1.c
--- work.old/buhg/dirmatr1.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirmatr1.c	Tue Jan 21 21:42:50 2003
@@ -495,7 +495,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu4_3.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu4_3.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
