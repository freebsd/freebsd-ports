diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vprovnbs.c work/buhg/vprovnbs.c
--- work.old/buhg/vprovnbs.c	Thu Jan 16 00:08:01 2003
+++ buhg/vprovnbs.c	Tue Jan 21 21:42:53 2003
@@ -354,7 +354,7 @@
     attroff(VV.VVOD_return_cs(iceb_CFS));
     GDITE();
 
-    sprintf(strsql,"%s/doc/%s",putnansi,"buhg3_1_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg3_1_1.txt");
     prosf(strsql);
 
     clear();
