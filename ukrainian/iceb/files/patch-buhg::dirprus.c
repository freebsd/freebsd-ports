diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirprus.c work/buhg/dirprus.c
--- work.old/buhg/dirprus.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirprus.c	Tue Jan 21 21:42:50 2003
@@ -334,7 +334,7 @@
   case FK1:   /*Получить подсказку*/
    GDITE();
 
-   sprintf(strsql,"%s/doc/%s",putnansi,"usl2_1_1_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"usl2_1_1_1.txt");
    prosf(strsql);
 
    clear();
