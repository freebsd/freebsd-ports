diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/smpld.c work/buhg/smpld.c
--- work.old/buhg/smpld.c	Thu Jan 16 00:07:58 2003
+++ buhg/smpld.c	Tue Jan 21 21:42:52 2003
@@ -360,7 +360,7 @@
 
     case FK1:   /*Помощь*/
       GDITE();
-      sprintf(strsql,"%s/doc/%s",putnansi,"dokum2_4.txt");
+      sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"dokum2_4.txt");
       prosf(strsql);
       clear();
       if(kolstr > 0)
