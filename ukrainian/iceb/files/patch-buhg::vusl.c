diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vusl.c work/buhg/vusl.c
--- work.old/buhg/vusl.c	Thu Jan 16 00:08:01 2003
+++ buhg/vusl.c	Tue Jan 21 21:42:53 2003
@@ -395,7 +395,7 @@
     {
      attroff(VV.VVOD_return_cs(iceb_CFS));
      GDITE();
-     sprintf(bros,"%s/doc/%s",putnansi,"usl2_1_1_2.txt");
+     sprintf(bros,"%s/%s",ICEB_DOC_PATH,"usl2_1_1_2.txt");
      prosf(bros);
      clear();
      goto naz;
