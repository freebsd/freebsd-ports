--- buhg/provtime.c.orig	Wed Oct  8 19:53:03 2003
+++ buhg/provtime.c	Wed Oct  8 19:53:09 2003
@@ -19,7 +19,7 @@
 {
 int		kom1=0;
 struct  tm      *bf;
-long            tmm;
+time_t            tmm;
 char		bros[100];
 short		dn,mn,gn,dk,mk,gk;
 char		strsql[300];
