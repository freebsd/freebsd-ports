diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/kasoth.c work/buhg/kasoth.c
--- work.old/buhg/kasoth.c	Thu Jan 16 00:07:53 2003
+++ buhg/kasoth.c	Tue Jan 21 21:42:50 2003
@@ -77,7 +77,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-//   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_2_1.txt");
+//   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_2_1.txt");
 //   prosf(bros);
    goto naz;
 
