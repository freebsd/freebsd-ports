diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/pgpld.c work/buhg/pgpld.c
--- work.old/buhg/pgpld.c	Thu Jan 16 00:07:54 2003
+++ buhg/pgpld.c	Tue Jan 21 21:42:51 2003
@@ -68,7 +68,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"dokum2_5.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"dokum2_5.txt");
    prosf(strsql);
    goto naz;
 
