diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/copdok.c work/buhg/copdok.c
--- work.old/buhg/copdok.c	Thu Jan 16 00:07:50 2003
+++ buhg/copdok.c	Tue Jan 21 21:42:49 2003
@@ -98,7 +98,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2d.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2d.txt");
    prosf(strsql);
    clear();
    goto naz;
