diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/poiprov.c work/buhg/poiprov.c
--- work.old/buhg/poiprov.c	Thu Jan 16 00:07:55 2003
+++ buhg/poiprov.c	Tue Jan 21 21:42:51 2003
@@ -130,7 +130,7 @@
 
     case FK1:
       GDITE();
-      sprintf(strsql,"%s/doc/%s",putnansi,"buhg3_3.txt");
+      sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg3_3.txt");
       prosf(strsql);
       clear();
       goto naz;
