diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/kategor.c work/buhg/kategor.c
--- work.old/buhg/kategor.c	Thu Jan 16 00:07:53 2003
+++ buhg/kategor.c	Tue Jan 21 21:42:50 2003
@@ -93,9 +93,9 @@
   case FK1:   /*Помощь*/
    GDITE();
    if(metkar == 0)
-     sprintf(bros,"%s/doc/%s",putnansi,"zarp4_2_1.txt");
+     sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_2_1.txt");
    if(metkar == 1)
-     sprintf(bros,"%s/doc/%s",putnansi,"zarp4_2_2.txt");
+     sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_2_2.txt");
    prosf(bros);
    goto naz;
 
