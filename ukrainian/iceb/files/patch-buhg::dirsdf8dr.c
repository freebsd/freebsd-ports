diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirsdf8dr.c work/buhg/dirsdf8dr.c
--- work.old/buhg/dirsdf8dr.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirsdf8dr.c	Tue Jan 21 21:42:50 2003
@@ -272,7 +272,7 @@
 
   case FK1: /*Помощь*/
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_7_1_2.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_7_1_2.txt");
     prosf(strsql);
     if(kolstr > 0)
       goto naz;
