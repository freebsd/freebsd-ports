diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirusl.c work/buhg/dirusl.c
--- work.old/buhg/dirusl.c	Thu Jan 16 00:07:52 2003
+++ buhg/dirusl.c	Tue Jan 21 21:42:50 2003
@@ -362,7 +362,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"usl3_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"usl3_2.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
