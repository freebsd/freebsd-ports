diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vkart.c work/buhg/vkart.c
--- work.old/buhg/vkart.c	Thu Jan 16 00:08:00 2003
+++ buhg/vkart.c	Tue Jan 21 21:42:52 2003
@@ -758,7 +758,7 @@
     case FK1:   /*Помощь*/
       attroff(VV.VVOD_return_cs(iceb_CFS));
       GDITE();
-      sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_1.txt");
+      sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_1.txt");
       prosf(strsql);
       clear();
       goto naz;
