diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/socstrm.c work/buhg/socstrm.c
--- work.old/buhg/socstrm.c	Thu Jan 16 00:07:58 2003
+++ buhg/socstrm.c	Tue Jan 21 21:42:52 2003
@@ -78,7 +78,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_7_4.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_7_4.txt");
    prosf(strsql);
    goto naz;
   case ESC:
