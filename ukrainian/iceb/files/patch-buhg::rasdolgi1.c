diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rasdolgi1.c work/buhg/rasdolgi1.c
--- work.old/buhg/rasdolgi1.c	Thu Jan 16 00:07:56 2003
+++ buhg/rasdolgi1.c	Tue Jan 21 21:42:51 2003
@@ -63,7 +63,7 @@
  {
   case FK1:
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_10.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_10.txt");
    prosf(strsql);
    goto naz;
   
