--- libutil/rsdat.c.orig	Wed Oct  8 18:50:26 2003
+++ libutil/rsdat.c	Wed Oct  8 18:50:35 2003
@@ -26,7 +26,7 @@
 {
 char            bros[100];
 struct  tm      *bf;
-long            tmm;
+time_t          tmm;
 short           god,mes;
 int		i;
 
