diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rashod.c work/buhg/rashod.c
--- work.old/buhg/rashod.c	Thu Jan 16 00:07:56 2003
+++ buhg/rashod.c	Tue Jan 21 21:42:51 2003
@@ -479,9 +479,9 @@
      attron(VV.VVOD_return_cs(iceb_CFM));
      GDITE();
      if(mdd == 0) /*Одинарный документ*/
-      sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2j.txt");
+      sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2j.txt");
      if(mdd == 1) /*Двойной документ*/
-      sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2j1.txt");
+      sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2j1.txt");
      prosf(strsql);
      clear();
      goto naz1;
