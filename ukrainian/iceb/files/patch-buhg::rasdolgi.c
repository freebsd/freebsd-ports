diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasdolgi.c work/buhg/rasdolgi.c
--- work.old/buhg/rasdolgi.c	Thu Jan 16 00:07:56 2003
+++ buhg/rasdolgi.c	Tue Jan 21 21:42:51 2003
@@ -158,7 +158,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_3_9.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_3_9.txt");
    prosf(bros);
    goto naz;
 
