diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirtabelo.c work/buhg/dirtabelo.c
--- work.old/buhg/dirtabelo.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirtabelo.c	Tue Jan 21 21:42:50 2003
@@ -295,7 +295,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_6.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_6.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
@@ -1006,7 +1006,7 @@
   if(K == FK1) /*Просмотр подсказки*/
    {  
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_6_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_6_1.txt");
     prosf(strsql);
     clear();
     goto naz;
