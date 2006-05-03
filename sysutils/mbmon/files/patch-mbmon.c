--- mbmon.c.orig	Fri Aug 13 09:23:32 2004
+++ mbmon.c	Wed May  3 21:32:44 2006
@@ -315,7 +315,7 @@
 
 	name = argv[0];
 #if !defined(LINUX) && defined(HAVE_SMBUS) && defined(SMBUS_IOCTL)
-	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:s:c:T:F:tunNirh")) != -1) {
+	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:s:c:T:F:tunNirhP:")) != -1) {
 #else
 	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:c:T:F:tunNirhP:")) != -1) {
 #endif
@@ -640,6 +640,7 @@
 		else if (fanspeed == 7)
 			fprintf(out, "%4d\n%4d\n%4d\n", rot1, rot2, rot3);
 	}
+	fflush(out);
 	if (port) {
 #ifdef LOGGING
 		if (nfd)
