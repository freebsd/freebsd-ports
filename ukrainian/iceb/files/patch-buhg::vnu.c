diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vnu.c work/buhg/vnu.c
--- work.old/buhg/vnu.c	Thu Jan 16 00:08:00 2003
+++ buhg/vnu.c	Tue Jan 21 21:42:53 2003
@@ -127,7 +127,7 @@
    {
     case FK1:   /*Помощь*/
      GDITE();
-     sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_2.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_2.txt");
      prosf(strsql);
      clear();
      goto naz;
