diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirudok.c work/buhg/dirudok.c
--- work.old/buhg/dirudok.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirudok.c	Tue Jan 21 21:42:50 2003
@@ -484,7 +484,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"usl2_1_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"usl2_1_1.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
