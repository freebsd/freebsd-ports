diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/diruosdok.c work/buhg/diruosdok.c
--- work.old/buhg/diruosdok.c	Thu Jan 16 00:07:51 2003
+++ buhg/diruosdok.c	Tue Jan 21 21:42:50 2003
@@ -336,7 +336,7 @@
     
   case FK1: /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"uos2_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"uos2_2.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
