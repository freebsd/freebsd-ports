--- util.c.orig	2004-01-22 22:25:39 UTC
+++ util.c
@@ -60,6 +60,7 @@ u_char zero[6] = { 0, 0, 0, 0, 0, 0 };
 u_char allones[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
 
 int debug = 0;
+int zeroflag = 0;
 int initializing = 1;			/* true if initializing */
 
 /* syslog() helper routine */
