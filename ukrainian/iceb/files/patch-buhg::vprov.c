--- buhg/vprov.c.orig	Mon Jul 29 10:28:37 2002
+++ buhg/vprov.c	Wed Oct  8 19:55:04 2003
@@ -22,7 +22,7 @@
 {
 char            bros[100];
 int		nm=3;
-long		vrem;
+time_t		vrem;
 char            nsh[20];
 char            nai[60];
 char            nai1[60];
@@ -561,7 +561,7 @@
      attroff(VV.VVOD_return_cs(iceb_CFS));
      GDITE();
 
-     sprintf(strsql,"%s/doc/%s",putnansi,"buhg3_1.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"buhg3_1.txt");
      prosf(strsql);
 
      clear();
