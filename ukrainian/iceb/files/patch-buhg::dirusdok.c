diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirusdok.c work/buhg/dirusdok.c
--- work.old/buhg/dirusdok.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirusdok.c	Tue Jan 21 21:42:50 2003
@@ -388,7 +388,7 @@
 
   case FK1: /*Помощь*/
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"usl2_3.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"usl2_3.txt");
     prosf(strsql);
     if(kolstr > 0)
       goto naz;
