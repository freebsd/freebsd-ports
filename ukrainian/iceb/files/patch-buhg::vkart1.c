diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vkart1.c work/buhg/vkart1.c
--- work.old/buhg/vkart1.c	Thu Jan 16 00:08:00 2003
+++ buhg/vkart1.c	Tue Jan 21 21:42:52 2003
@@ -269,7 +269,7 @@
       attroff(VV.VVOD_return_cs(iceb_CFS));
       attron(VV.VVOD_return_cs(iceb_CFM));
       GDITE();
-      sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_3.txt");
+      sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_3.txt");
       prosf(strsql);
       clear();
       goto naz;
