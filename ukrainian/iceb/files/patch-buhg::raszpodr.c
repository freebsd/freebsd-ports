diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/raszpodr.c work/buhg/raszpodr.c
--- work.old/buhg/raszpodr.c	Thu Jan 16 00:07:57 2003
+++ buhg/raszpodr.c	Tue Jan 21 21:42:51 2003
@@ -75,7 +75,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_8.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_8.txt");
    prosf(bros);
    goto naz;
 
