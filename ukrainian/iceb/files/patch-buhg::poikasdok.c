diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/poikasdok.c work/buhg/poikasdok.c
--- work.old/buhg/poikasdok.c	Thu Jan 16 00:07:55 2003
+++ buhg/poikasdok.c	Tue Jan 21 21:42:51 2003
@@ -45,7 +45,7 @@
 if(i == FK1)
  {
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"kas5.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"kas5.txt");
    prosf(strsql);
    clear();
    goto naz2;
