diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirprmu.c work/buhg/dirprmu.c
--- work.old/buhg/dirprmu.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirprmu.c	Tue Jan 21 21:42:50 2003
@@ -356,7 +356,7 @@
 
   case FK1:   /*Получить подсказку*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2a.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2a.txt");
    prosf(strsql);
    clear();
    goto naz1;
