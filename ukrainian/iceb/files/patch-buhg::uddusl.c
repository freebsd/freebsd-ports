diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/uddusl.c work/buhg/uddusl.c
--- work.old/buhg/uddusl.c	Thu Jan 16 00:07:59 2003
+++ buhg/uddusl.c	Tue Jan 21 21:42:52 2003
@@ -41,7 +41,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"usl2_4.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"usl2_4.txt");
    prosf(strsql);
    goto naz;
 
