diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarsprvmn.c work/buhg/zarsprvmn.c
--- work.old/buhg/zarsprvmn.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarsprvmn.c	Tue Jan 21 21:42:54 2003
@@ -90,7 +90,7 @@
  {
   case FK1:
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_13.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_13.txt");
     prosf(strsql);
     goto naz;
 
