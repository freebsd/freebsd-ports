diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/poimatdok.c work/buhg/poimatdok.c
--- work.old/buhg/poimatdok.c	Thu Jan 16 00:07:55 2003
+++ buhg/poimatdok.c	Tue Jan 21 21:42:51 2003
@@ -45,7 +45,7 @@
 if(i == FK1)
  {
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu2_2.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_2.txt");
    prosf(strsql);
    clear();
    goto naz2;
