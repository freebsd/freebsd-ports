diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/otrshd.c work/buhg/otrshd.c
--- work.old/buhg/otrshd.c	Thu Jan 16 00:07:54 2003
+++ buhg/otrshd.c	Tue Jan 21 21:42:51 2003
@@ -86,7 +86,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_2_3.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_2_3.txt");
    prosf(bros);
    goto naz;
 
