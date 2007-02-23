--- utils.c.orig	Fri Feb 23 07:31:48 2007
+++ utils.c	Fri Feb 23 07:34:20 2007
@@ -58,7 +58,11 @@
 static char base64[64];
 static char b2a[256];
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined( __NetBSD__ ) || defined(__APPLE__) || defined(__CYGWIN__)
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#endif
+
+#if (defined(__FreeBSD__) && __FreeBSD_version < 601103) || defined(__OpenBSD__) || defined( __NetBSD__ ) || defined(__APPLE__) || defined(__CYGWIN__)
 
 /* duh? ERANGE value copied from web... */
 #define ERANGE 34
