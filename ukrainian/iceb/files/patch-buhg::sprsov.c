diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/sprsov.c work/buhg/sprsov.c
--- work.old/buhg/sprsov.c	Thu Jan 16 00:07:59 2003
+++ buhg/sprsov.c	Tue Jan 21 21:42:52 2003
@@ -141,7 +141,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_8.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_8.txt");
    prosf(strsql);
    goto naz;
 
