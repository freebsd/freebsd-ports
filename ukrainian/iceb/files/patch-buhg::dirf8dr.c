diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirf8dr.c work/buhg/dirf8dr.c
--- work.old/buhg/dirf8dr.c	Thu Jan 16 00:07:50 2003
+++ buhg/dirf8dr.c	Tue Jan 21 21:42:49 2003
@@ -380,7 +380,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_7_1_2_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_7_1_2_2.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
