diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rozkor.c work/buhg/rozkor.c
--- work.old/buhg/rozkor.c	Thu Jan 16 00:07:57 2003
+++ buhg/rozkor.c	Tue Jan 21 21:42:52 2003
@@ -108,7 +108,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2c.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2c.txt");
    prosf(strsql);
    clear();
    goto naz;
