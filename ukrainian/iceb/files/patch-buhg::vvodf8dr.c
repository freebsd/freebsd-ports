diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vvodf8dr.c work/buhg/vvodf8dr.c
--- work.old/buhg/vvodf8dr.c	Thu Jan 16 00:08:01 2003
+++ buhg/vvodf8dr.c	Tue Jan 21 21:42:53 2003
@@ -164,7 +164,7 @@
   if(K == FK1)
    {
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_7_1_2_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_7_1_2_1.txt");
     prosf(strsql);
     clear();
     goto nazad;
