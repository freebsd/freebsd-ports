diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/perras.c work/buhg/perras.c
--- work.old/buhg/perras.c	Thu Jan 16 00:07:54 2003
+++ buhg/perras.c	Tue Jan 21 21:42:51 2003
@@ -98,7 +98,7 @@
 
     case 4:
      GDITE();
-     sprintf(bros,"%s/doc/%s",putnansi,"zarp4_3_7.txt");
+     sprintf(bros,"%s/%s",ICEB_DOC_PATH,"zarp4_3_7.txt");
      prosf(bros);
      break;
    }
