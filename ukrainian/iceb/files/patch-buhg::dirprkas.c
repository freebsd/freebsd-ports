diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirprkas.c work/buhg/dirprkas.c
--- work.old/buhg/dirprkas.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirprkas.c	Tue Jan 21 21:42:50 2003
@@ -378,7 +378,7 @@
   case FK1:   /*Получить подсказку*/
    GDITE();
 
-   sprintf(strsql,"%s/doc/%s",putnansi,"kas2_1_1_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"kas2_1_1_1.txt");
    prosf(strsql);
 
    clear();
