diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarrasp.c work/buhg/zarrasp.c
--- work.old/buhg/zarrasp.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarrasp.c	Tue Jan 21 21:42:54 2003
@@ -100,7 +100,7 @@
   case FK1:   /*Помощь*/
    GDITE();
 
-   sprintf(bros,"%s/doc/%s",putnansi,"zarp4_7_5.txt");
+   sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_7_5.txt");
    prosf(bros);
 
    goto naz;
