diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/smdok1.c work/buhg/smdok1.c
--- work.old/buhg/smdok1.c	Thu Jan 16 00:07:58 2003
+++ buhg/smdok1.c	Tue Jan 21 21:42:52 2003
@@ -327,7 +327,7 @@
  {  
   case FK1: /*Помощь*/
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"matu2_3.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_3.txt");
     prosf(strsql);
     if(kolstr > 0)
       goto naz;
