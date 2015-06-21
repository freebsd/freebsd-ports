--- mbmon.c.orig	2015-05-28 10:06:29 UTC
+++ mbmon.c
@@ -315,7 +315,7 @@ int main(int argc, char *argv[])
 
 	name = argv[0];
 #if !defined(LINUX) && defined(HAVE_SMBUS) && defined(SMBUS_IOCTL)
-	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:s:c:T:F:tunNirh")) != -1) {
+	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:s:c:T:F:tunNirhP:")) != -1) {
 #else
 	while ((ch = getopt(argc,argv,"VSIAfdDYe:p:c:T:F:tunNirhP:")) != -1) {
 #endif
@@ -642,6 +642,7 @@ int main(int argc, char *argv[])
 	}
 	fflush(out);
 	if (port) {
+		fflush(out);
 #ifdef LOGGING
 		if (nfd)
 #endif
@@ -660,6 +661,7 @@ int main(int argc, char *argv[])
 	if (hostname_flag == 1) {
 		hostname(sh_flag);
 	}
+	fflush(stdout);
 
 /* count */
 	if (count != 0) {
