diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vprovgr.c work/buhg/vprovgr.c
--- work.old/buhg/vprovgr.c	Thu Jan 16 00:08:01 2003
+++ buhg/vprovgr.c	Tue Jan 21 21:42:53 2003
@@ -278,7 +278,7 @@
      attroff(VV.VVOD_return_cs(iceb_CFS));
      GDITE();
 
-     sprintf(strsql,"%s/doc/%s",putnansi,"buhg3_4.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg3_4.txt");
      prosf(strsql);
 
      clear();
