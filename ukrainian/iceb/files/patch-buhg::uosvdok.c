diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/uosvdok.c work/buhg/uosvdok.c
--- work.old/buhg/uosvdok.c	Thu Jan 16 00:08:00 2003
+++ buhg/uosvdok.c	Tue Jan 21 21:42:52 2003
@@ -748,9 +748,9 @@
      attroff(VV->VVOD_return_cs(iceb_CFS)); 
      GDITE();
      if(uos.tipz == 1)
-       sprintf(strsql,"%s/doc/%s",putnansi,"uos2_1_1.txt");
+       sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"uos2_1_1.txt");
      if(uos.tipz == 2)
-       sprintf(strsql,"%s/doc/%s",putnansi,"uos2_1_2.txt");
+       sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"uos2_1_2.txt");
      prosf(strsql);
      clear();
      goto nazad;
