diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarsprsoc.c work/buhg/zarsprsoc.c
--- work.old/buhg/zarsprsoc.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarsprsoc.c	Tue Jan 21 21:42:54 2003
@@ -74,7 +74,7 @@
  {
   case FK1:
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_7_7.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_7_7.txt");
    prosf(strsql);
    goto naz;
   
