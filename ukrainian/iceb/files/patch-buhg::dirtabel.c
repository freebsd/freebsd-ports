diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirtabel.c work/buhg/dirtabel.c
--- work.old/buhg/dirtabel.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirtabel.c	Tue Jan 21 21:42:50 2003
@@ -262,7 +262,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_4.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_4.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
