diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/kassa.c work/buhg/kassa.c
--- work.old/buhg/kassa.c	Thu Jan 16 00:07:53 2003
+++ buhg/kassa.c	Tue Jan 21 21:42:50 2003
@@ -396,10 +396,10 @@
   case 1 :
    GDITE();
     if(tipkas == T_DATECS)
-     sprintf(strsql,"%s/doc/%s",putnansi,"datecs_reset.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"datecs_reset.txt");
 
    if(tipkas == T_ERA)
-     sprintf(strsql,"%s/doc/%s",putnansi,"era_reset.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"era_reset.txt");
 
    prosf(strsql);
    goto naz;
