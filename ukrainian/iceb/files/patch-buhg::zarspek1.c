diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarspek1.c work/buhg/zarspek1.c
--- work.old/buhg/zarspek1.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarspek1.c	Tue Jan 21 21:42:54 2003
@@ -60,7 +60,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_7_6.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_7_6.txt");
    prosf(bros);
    goto naz;
 
