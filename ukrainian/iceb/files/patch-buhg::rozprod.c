diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rozprod.c work/buhg/rozprod.c
--- work.old/buhg/rozprod.c	Thu Jan 16 00:07:57 2003
+++ buhg/rozprod.c	Tue Jan 21 21:42:52 2003
@@ -359,7 +359,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"rozn1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"rozn1.txt");
    prosf(strsql);
    goto naz1;
 
