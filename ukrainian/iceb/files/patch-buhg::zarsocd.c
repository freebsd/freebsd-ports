diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/zarsocd.c work/buhg/zarsocd.c
--- work.old/buhg/zarsocd.c	Thu Jan 16 00:08:02 2003
+++ buhg/zarsocd.c	Tue Jan 21 21:42:54 2003
@@ -69,7 +69,7 @@
  {
   case FK1:
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_7_8.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_7_8.txt");
    prosf(strsql);
    goto naz;
   
