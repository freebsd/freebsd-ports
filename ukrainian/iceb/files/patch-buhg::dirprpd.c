diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirprpd.c work/buhg/dirprpd.c
--- work.old/buhg/dirprpd.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirprpd.c	Tue Jan 21 21:42:50 2003
@@ -399,7 +399,7 @@
 
   case FK1:   /*Получение подсказки*/
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"dokum2_1_2.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"dokum2_1_2.txt");
     prosf(strsql);
     clear();
     if(kolstr > 0)
