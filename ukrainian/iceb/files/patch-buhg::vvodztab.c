diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vvodztab.c work/buhg/vvodztab.c
--- work.old/buhg/vvodztab.c	Thu Jan 16 00:08:01 2003
+++ buhg/vvodztab.c	Tue Jan 21 21:42:53 2003
@@ -346,7 +346,7 @@
   if(K == FK1) /*Просмотр подсказки*/
    {  
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_6_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_6_1.txt");
     prosf(strsql);
     clear();
     goto naz;
