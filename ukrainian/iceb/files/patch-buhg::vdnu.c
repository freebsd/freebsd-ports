diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vdnu.c work/buhg/vdnu.c
--- work.old/buhg/vdnu.c	Thu Jan 16 00:08:00 2003
+++ buhg/vdnu.c	Tue Jan 21 21:42:52 2003
@@ -561,7 +561,7 @@
      attroff(VV->VVOD_return_cs(iceb_CFS));
      attron(VV->VVOD_return_cs(iceb_CFM));
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"usl2_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"usl2_1.txt");
     prosf(strsql);
     clear();
     goto nazad;
