diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/sprpen1.c work/buhg/sprpen1.c
--- work.old/buhg/sprpen1.c	Thu Jan 16 00:07:58 2003
+++ buhg/sprpen1.c	Tue Jan 21 21:42:52 2003
@@ -129,7 +129,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_7_3.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_7_3.txt");
    prosf(bros);
    goto naz;
   case FK2:
