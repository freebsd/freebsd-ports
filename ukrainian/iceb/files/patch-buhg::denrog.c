diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/denrog.c work/buhg/denrog.c
--- work.old/buhg/denrog.c	Thu Jan 16 00:07:50 2003
+++ buhg/denrog.c	Tue Jan 21 21:42:49 2003
@@ -82,7 +82,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_1_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_1_1.txt");
    prosf(strsql);
    goto naz;
 
