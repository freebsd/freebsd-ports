diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirsoc.c work/buhg/dirsoc.c
--- work.old/buhg/dirsoc.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirsoc.c	Tue Jan 21 21:42:50 2003
@@ -277,7 +277,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_9.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_9.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
