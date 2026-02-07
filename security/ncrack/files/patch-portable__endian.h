--- portable_endian.h.orig	2019-08-24 22:25:32 UTC
+++ portable_endian.h
@@ -18,6 +18,7 @@
 #   include <endian.h>
 #   include <features.h>
 /* See http://linux.die.net/man/3/endian */
+#   if !defined(__FreeBSD__)
 #   if !defined(__GLIBC__) || !defined(__GLIBC_MINOR__) || ((__GLIBC__ < 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ < 9))) 
 #       include <arpa/inet.h>
 #       if defined(__BYTE_ORDER) && (__BYTE_ORDER == __LITTLE_ENDIAN)
@@ -54,6 +55,7 @@
 #           error Byte Order not supported or not defined.
 #       endif
 #   endif
+#   endif
 
 
 
@@ -81,11 +83,11 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined (__FreeBSD__)
 
 #	include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__NetBSD__) || defined(__DragonFly__)
 
 #	include <sys/endian.h>
 
