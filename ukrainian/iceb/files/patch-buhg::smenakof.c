diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/smenakof.c work/buhg/smenakof.c
--- work.old/buhg/smenakof.c	Thu Jan 16 00:07:58 2003
+++ buhg/smenakof.c	Tue Jan 21 21:42:52 2003
@@ -71,7 +71,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"uos5_9.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"uos5_9.txt");
    prosf(strsql);
    goto naz;
 
