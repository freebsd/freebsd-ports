diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirtab.c work/buhg/dirtab.c
--- work.old/buhg/dirtab.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirtab.c	Tue Jan 21 21:42:50 2003
@@ -319,7 +319,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_5.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_5.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
