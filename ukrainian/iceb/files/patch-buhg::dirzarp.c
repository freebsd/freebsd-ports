diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirzarp.c work/buhg/dirzarp.c
--- work.old/buhg/dirzarp.c	Thu Jan 16 00:07:52 2003
+++ buhg/dirzarp.c	Tue Jan 21 21:42:50 2003
@@ -351,7 +351,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_2.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
@@ -771,7 +771,7 @@
   case FK1:   /*Помощь*/
    clear();
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_2_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_2_1.txt");
    prosf(strsql);
    
    goto naz;
