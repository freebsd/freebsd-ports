diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirprzar.c work/buhg/dirprzar.c
--- work.old/buhg/dirprzar.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirprzar.c	Tue Jan 21 21:42:50 2003
@@ -349,7 +349,7 @@
 
   case FK1:   /*Получить подсказку*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_1_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_1_1.txt");
    prosf(strsql);
    clear();
    goto naz1;
@@ -567,7 +567,7 @@
         
       case FK1:
         GDITE();
-        sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_1_1_1.txt");
+        sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_1_1_1.txt");
         prosf(strsql);
         clear();
         goto sfk4;
