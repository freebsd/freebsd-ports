diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/diros.c work/buhg/diros.c
--- work.old/buhg/diros.c	Thu Jan 16 00:07:51 2003
+++ buhg/diros.c	Tue Jan 21 21:42:50 2003
@@ -318,7 +318,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"uos4.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"uos4.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
