diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/glkninbs.c work/buhg/glkninbs.c
--- work.old/buhg/glkninbs.c	Thu Jan 16 00:07:52 2003
+++ buhg/glkninbs.c	Tue Jan 21 21:42:50 2003
@@ -92,7 +92,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"buhg5_1_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg5_1_1.txt");
    prosf(strsql);
    goto naz;
 
