diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/sprkvrt.c work/buhg/sprkvrt.c
--- work.old/buhg/sprkvrt.c	Thu Jan 16 00:07:58 2003
+++ buhg/sprkvrt.c	Tue Jan 21 21:42:52 2003
@@ -223,7 +223,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_7_1_1.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_7_1_1.txt");
    prosf(bros);
    goto naz;
 
