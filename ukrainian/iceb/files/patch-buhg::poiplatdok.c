diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/poiplatdok.c work/buhg/poiplatdok.c
--- work.old/buhg/poiplatdok.c	Thu Jan 16 00:07:55 2003
+++ buhg/poiplatdok.c	Tue Jan 21 21:42:51 2003
@@ -49,7 +49,7 @@
 if(i == FK1)
  {
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu2_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_2.txt");
    prosf(strsql);
    clear();
    goto naz2;
