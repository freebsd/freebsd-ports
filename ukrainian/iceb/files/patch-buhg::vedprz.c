diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vedprz.c work/buhg/vedprz.c
--- work.old/buhg/vedprz.c	Thu Jan 16 00:08:00 2003
+++ buhg/vedprz.c	Tue Jan 21 21:42:52 2003
@@ -110,7 +110,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_5_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_5_1.txt");
    prosf(strsql);
    goto naz;
   case ESC:
