diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirpzpd.c work/buhg/dirpzpd.c
--- work.old/buhg/dirpzpd.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirpzpd.c	Tue Jan 21 21:42:50 2003
@@ -255,7 +255,7 @@
      break;
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"dokum2_1_3.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"dokum2_1_3.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
