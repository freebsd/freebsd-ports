diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarkart.c work/buhg/zarkart.c
--- work.old/buhg/zarkart.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarkart.c	Tue Jan 21 21:42:54 2003
@@ -97,7 +97,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_3_12.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_3_12.txt");
    prosf(bros);
    goto naz;
 
