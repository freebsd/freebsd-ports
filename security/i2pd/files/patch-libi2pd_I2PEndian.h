--- libi2pd/I2PEndian.h.orig	2017-12-04 18:40:32 UTC
+++ libi2pd/I2PEndian.h
@@ -3,10 +3,10 @@
 #include <inttypes.h>
 #include <string.h>
 
-#if defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
-#include <endian.h>
-#elif __FreeBSD__
+#if defined(__FreeBSD__)
 #include <sys/endian.h>
+#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#include <endian.h>
 #elif defined(__APPLE__) && defined(__MACH__)
 
 #include <libkern/OSByteOrder.h>
