diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/svodnu.c work/buhg/svodnu.c
--- work.old/buhg/svodnu.c	Thu Jan 16 00:07:59 2003
+++ buhg/svodnu.c	Tue Jan 21 21:42:52 2003
@@ -116,7 +116,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp4_3_6.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp4_3_6.txt");
    prosf(strsql);
    clear();
   case FK10:
