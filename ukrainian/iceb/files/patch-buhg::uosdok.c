diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/uosdok.c work/buhg/uosdok.c
--- work.old/buhg/uosdok.c	Thu Jan 16 00:07:59 2003
+++ buhg/uosdok.c	Tue Jan 21 21:42:52 2003
@@ -455,7 +455,7 @@
 
   case FK1:   /*Получение подсказки*/
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"uos2_1_3.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"uos2_1_3.txt");
     prosf(strsql);
     clear();
 
