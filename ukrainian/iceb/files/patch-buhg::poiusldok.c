diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/poiusldok.c work/buhg/poiusldok.c
--- work.old/buhg/poiusldok.c	Thu Jan 16 00:07:55 2003
+++ buhg/poiusldok.c	Tue Jan 21 21:42:51 2003
@@ -44,7 +44,7 @@
 if(i == FK1)
  {
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"usl2_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"usl2_2.txt");
    prosf(strsql);
    clear();
    goto naz2;
