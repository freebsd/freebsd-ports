diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarspek.c work/buhg/zarspek.c
--- work.old/buhg/zarspek.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarspek.c	Tue Jan 21 21:42:54 2003
@@ -104,7 +104,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_7_2.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_7_2.txt");
    prosf(bros);
    goto naz;
 
