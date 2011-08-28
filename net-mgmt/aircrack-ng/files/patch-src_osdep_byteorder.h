--- src/osdep/byteorder.h.orig	2011-08-28 18:26:15.000000000 +0200
+++ src/osdep/byteorder.h	2011-08-28 18:26:25.000000000 +0200
@@ -167,7 +167,7 @@
 	 * Solaris
 	 * -------
 	 */
-	#if defined(__sparc__)
+	#if defined(__sun) && defined(__SVR4) && defined(__sparc__)
 	#include <sys/byteorder.h>
 	#include <sys/types.h>
 	#include <unistd.h>
