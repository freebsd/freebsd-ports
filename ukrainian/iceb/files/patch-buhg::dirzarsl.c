diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirzarsl.c work/buhg/dirzarsl.c
--- work.old/buhg/dirzarsl.c	Thu Jan 16 00:07:52 2003
+++ buhg/dirzarsl.c	Tue Jan 21 22:49:25 2003
@@ -218,7 +218,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/zarp3_1_9.txt",putnansi);
+   sprintf(strsql,"%s/zarp3_1_9.txt",ICEB_DOC_PATH);
    prosf(strsql);
    clear();
    goto naz;
