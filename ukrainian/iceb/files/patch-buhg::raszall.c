diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/raszall.c work/buhg/raszall.c
--- work.old/buhg/raszall.c	Thu Jan 16 00:07:57 2003
+++ buhg/raszall.c	Tue Jan 21 21:42:51 2003
@@ -76,7 +76,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp2_7.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp2_7.txt");
    prosf(bros);
    goto naz;
 
