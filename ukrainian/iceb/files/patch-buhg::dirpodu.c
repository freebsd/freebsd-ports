diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirpodu.c work/buhg/dirpodu.c
--- work.old/buhg/dirpodu.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirpodu.c	Tue Jan 21 21:42:50 2003
@@ -633,7 +633,7 @@
 
   case FK1:       /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu3.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu3.txt");
 //   prosf(strsql);
    if(kolstr > 0)
       goto naz;
