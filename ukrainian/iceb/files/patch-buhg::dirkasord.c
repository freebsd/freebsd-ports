diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirkasord.c work/buhg/dirkasord.c
--- work.old/buhg/dirkasord.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirkasord.c	Tue Jan 21 21:42:49 2003
@@ -289,7 +289,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"kas2_1_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"kas2_1_1.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
