--- src/osdep/byteorder.h.orig	2016-04-28 20:42:03 UTC
+++ src/osdep/byteorder.h
@@ -181,7 +181,7 @@
 	 * Solaris
 	 * -------
 	 */
-	#if defined(__SVR4) && defined(__sun__)
+	#if defined(__sparc__) && defined(__SVR4) && defined(__sun__)
 	#include <sys/byteorder.h>
 	#include <sys/types.h>
 	#include <unistd.h>
