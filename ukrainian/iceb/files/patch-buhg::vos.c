diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vos.c work/buhg/vos.c
--- work.old/buhg/vos.c	Thu Jan 16 00:08:00 2003
+++ buhg/vos.c	Tue Jan 21 21:42:53 2003
@@ -427,7 +427,7 @@
     case FK1:   /*Помощь*/
      attroff(VV->VVOD_return_cs(iceb_CFS)); 
      GDITE();
-     sprintf(strsql,"%s/doc/%s",putnansi,"uos3.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"uos3.txt");
      prosf(strsql);
      clear();
      goto naz;
