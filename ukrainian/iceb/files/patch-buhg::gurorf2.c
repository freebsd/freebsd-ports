--- buhg/gurorf2.c.orig	Wed Oct  8 19:50:48 2003
+++ buhg/gurorf2.c	Wed Oct  8 19:50:54 2003
@@ -41,7 +41,7 @@
 double		dendebet=0.,denkredit=0.;
 short		godn=0;
 struct  tm      *bf;
-long            tmm;
+time_t            tmm;
 char		imaf[30],imafd[30],imafi[30];
 FILE		*ff,*ffd;
 char		naikon[80];
