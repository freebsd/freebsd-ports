diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirkasords.c work/buhg/dirkasords.c
--- work.old/buhg/dirkasords.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirkasords.c	Tue Jan 21 21:42:49 2003
@@ -358,7 +358,7 @@
 
   case FK1: /*Помощь*/
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"kas2_4.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"kas2_4.txt");
     prosf(strsql);
     if(kolstr > 0)
       goto naz;
