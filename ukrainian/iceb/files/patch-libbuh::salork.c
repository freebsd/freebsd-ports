--- libbuh/salork.c.orig	Wed Oct  8 18:59:01 2003
+++ libbuh/salork.c	Wed Oct  8 18:59:13 2003
@@ -34,7 +34,7 @@
 )
 {
 char            bros[100];
-long            tmm;
+time_t            tmm;
 struct  tm      *bf;
 short           d,m,g;
 char            shet[10];
