diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasoskr.c work/buhg/rasoskr.c
--- work.old/buhg/rasoskr.c	Thu Jan 16 00:07:56 2003
+++ buhg/rasoskr.c	Tue Jan 21 21:42:51 2003
@@ -129,7 +129,7 @@
     return;
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu5_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu5_1.txt");
    prosf(strsql);
    clear();
    goto naz;
