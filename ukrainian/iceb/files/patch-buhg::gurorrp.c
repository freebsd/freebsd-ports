--- buhg/gurorrp.c.orig	Wed Oct  8 19:51:25 2003
+++ buhg/gurorrp.c	Wed Oct  8 19:51:33 2003
@@ -31,7 +31,7 @@
 char		imaf[30],imafs[30];
 FILE		*ff;
 struct  tm      *bf;
-long            tmm,tmmk;
+time_t            tmm,tmmk;
 int		kolstlst=0;
 
 clear();
