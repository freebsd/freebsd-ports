diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vmat.c work/buhg/vmat.c
--- work.old/buhg/vmat.c	Thu Jan 16 00:08:00 2003
+++ buhg/vmat.c	Tue Jan 21 21:42:52 2003
@@ -608,7 +608,7 @@
    if(cp == 1)
     {
      GDITE();
-     sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2f.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2f.txt");
      prosf(strsql);
      clear();
     }
@@ -616,14 +616,14 @@
    if(tipz == 1 && cp == 0)
     {
      GDITE();
-     sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2g.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2g.txt");
      prosf(strsql);
      clear();
     }
    if(tipz == 2 && cp == 0)
     {
      GDITE();
-     sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2s.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2s.txt");
      prosf(strsql);
      clear();
     }
@@ -1318,7 +1318,7 @@
    {
     attroff(VV.VVOD_return_cs(iceb_CFS));
     GDITE();
-    sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2g1.txt");
+    sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2g1.txt");
     prosf(strsql);
     clear();
     goto naz;
