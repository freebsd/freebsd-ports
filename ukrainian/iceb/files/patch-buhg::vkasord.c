diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/vkasord.c work/buhg/vkasord.c
--- work.old/buhg/vkasord.c	Thu Jan 16 00:08:00 2003
+++ buhg/vkasord.c	Tue Jan 21 21:42:52 2003
@@ -438,9 +438,9 @@
     attron(VV->VVOD_return_cs(iceb_CB));
     GDITE();
     if(tipz == 1)
-     sprintf(strsql,"%s/doc/%s",putnansi,"kas2_2.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"kas2_2.txt");
     if(tipz == 2)
-     sprintf(strsql,"%s/doc/%s",putnansi,"kas2_1.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"kas2_1.txt");
     prosf(strsql);
     goto nazad;
    }
