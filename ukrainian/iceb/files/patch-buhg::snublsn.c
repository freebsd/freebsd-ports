diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/snublsn.c work/buhg/snublsn.c
--- work.old/buhg/snublsn.c	Thu Jan 16 00:07:58 2003
+++ buhg/snublsn.c	Tue Jan 21 21:42:52 2003
@@ -77,7 +77,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_5_2.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_5_2.txt");
    prosf(bros);
    goto naz;
 
