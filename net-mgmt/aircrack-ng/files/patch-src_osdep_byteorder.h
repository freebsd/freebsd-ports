--- src/osdep/byteorder.h.orig	2013-03-04 18:32:55.000000000 +0100
+++ src/osdep/byteorder.h	2013-09-29 13:48:25.382520852 +0200
@@ -181,7 +181,7 @@
 	 * Solaris
 	 * -------
 	 */
-	#if defined(__sparc__) && defined(__sun__)
+	#if defined(__sparc__) && defined(__SVR4) && defined(__sun__)
 	#include <sys/byteorder.h>
 	#include <sys/types.h>
 	#include <unistd.h>
@@ -223,7 +223,9 @@
 
 	// FreeBSD
 	#ifdef __FreeBSD__
-		#include <machine/endian.h>
+		#undef ushort
+		#undef uint
+		#include <sys/types.h>
 	#endif
 
 	// XXX: Is there anything to include on OpenBSD/NetBSD/DragonFlyBSD/...?
