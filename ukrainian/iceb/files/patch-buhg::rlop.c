diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/rlop.c work/buhg/rlop.c
--- work.old/buhg/rlop.c	Thu Jan 16 00:07:57 2003
+++ buhg/rlop.c	Tue Jan 21 21:42:52 2003
@@ -70,7 +70,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-//   sprintf(strsql,"%s/doc/%s",putnansi,"buhg5_1.txt");
+//   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg5_1.txt");
 //   prosf(strsql);
    goto naz;
 
