$FreeBSD$

--- mbmon.c	Fri Aug 13 10:23:32 2004
+++ mbmon.c	Tue Dec 27 16:59:48 2005
@@ -315,7 +315,7 @@
 
 	name = argv[0];
 #if !defined(LINUX) && defined(HAVE_SMBUS) && defined(SMBUS_IOCTL)
-	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:s:c:T:F:tunNirh")) != -1) {
+	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:s:c:T:F:tunNirhP:")) != -1) {
 #else
 	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:c:T:F:tunNirhP:")) != -1) {
 #endif
