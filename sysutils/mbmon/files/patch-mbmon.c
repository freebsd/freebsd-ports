--- mbmon.c.orig	2004-08-13 16:23:32.000000000 +0900
+++ mbmon.c	2009-06-10 12:13:47.000000000 +0900
@@ -315,7 +315,7 @@
 
 	name = argv[0];
 #if !defined(LINUX) && defined(HAVE_SMBUS) && defined(SMBUS_IOCTL)
-	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:s:c:T:F:tunNirh")) != -1) {
+	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:s:c:T:F:tunNirhP:")) != -1) {
 #else
 	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:c:T:F:tunNirhP:")) != -1) {
 #endif
@@ -641,6 +641,7 @@
 			fprintf(out, "%4d\n%4d\n%4d\n", rot1, rot2, rot3);
 	}
 	if (port) {
+		fflush(out);
 #ifdef LOGGING
 		if (nfd)
 #endif
@@ -659,6 +660,7 @@
 	if (hostname_flag == 1) {
 		hostname(sh_flag);
 	}
+	fflush(stdout);
 
 /* count */
 	if (count != 0) {
