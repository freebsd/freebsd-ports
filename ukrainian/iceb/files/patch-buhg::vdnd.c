diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vdnd.c work/buhg/vdnd.c
--- work.old/buhg/vdnd.c	Thu Jan 16 00:08:00 2003
+++ buhg/vdnd.c	Tue Jan 21 21:42:52 2003
@@ -785,7 +785,7 @@
     attroff(VV->VVOD_return_cs(iceb_CFS));
     attron(VV->VVOD_return_cs(iceb_CB));
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_1.txt");
     prosf(strsql);
     goto nazad;
    }
