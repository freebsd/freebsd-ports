diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/uosinved.c work/buhg/uosinved.c
--- work.old/buhg/uosinved.c	Thu Jan 16 00:07:59 2003
+++ buhg/uosinved.c	Tue Jan 21 21:42:52 2003
@@ -109,7 +109,7 @@
 
   case FK1:
     GDITE();
-//    sprintf(bros,"%s/doc/%s",putnansi,"matu5_5.txt");
+//    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu5_5.txt");
 //    prosf(bros);
 //    clear();
     goto naz;
