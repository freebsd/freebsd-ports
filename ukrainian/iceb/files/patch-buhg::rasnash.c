diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasnash.c work/buhg/rasnash.c
--- work.old/buhg/rasnash.c	Thu Jan 16 00:07:56 2003
+++ buhg/rasnash.c	Tue Jan 21 21:42:51 2003
@@ -71,7 +71,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-//   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_2_2.txt");
+//   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_2_2.txt");
 //   prosf(bros);
    goto naz;
 
