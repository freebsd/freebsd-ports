diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirobq.c work/buhg/dirobq.c
--- work.old/buhg/dirobq.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirobq.c	Tue Jan 21 21:42:50 2003
@@ -289,7 +289,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"dokum4.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"dokum4.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
