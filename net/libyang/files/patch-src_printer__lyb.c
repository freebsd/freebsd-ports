--- src/printer_lyb.c.orig	2019-03-14 23:35:50 UTC
+++ src/printer_lyb.c
@@ -21,6 +21,8 @@
 #ifdef __APPLE__
 # include <libkern/OSByteOrder.h>
 # define htole64(x) OSSwapHostToLittleInt64(x)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+# include <sys/endian.h>
 #else
 # include <endian.h>
 #endif
