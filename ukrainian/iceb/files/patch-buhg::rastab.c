diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rastab.c work/buhg/rastab.c
--- work.old/buhg/rastab.c	Thu Jan 16 00:07:57 2003
+++ buhg/rastab.c	Tue Jan 21 21:42:51 2003
@@ -80,7 +80,7 @@
  {
   case FK1:
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_5.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_5.txt");
    prosf(strsql);
    clear();
    goto naz;
