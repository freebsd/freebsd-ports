diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarstomn.c work/buhg/zarstomn.c
--- work.old/buhg/zarstomn.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarstomn.c	Tue Jan 21 21:42:54 2003
@@ -71,7 +71,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-//   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_2_1.txt");
+//   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_2_1.txt");
 //   prosf(bros);
    goto naz;
 
