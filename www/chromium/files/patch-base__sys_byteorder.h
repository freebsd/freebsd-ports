--- base/sys_byteorder.h.orig	2012-03-30 01:34:16.000000000 +0300
+++ base/sys_byteorder.h	2012-03-30 01:35:48.000000000 +0300
@@ -27,7 +27,7 @@
 #include <stdlib.h>
 #elif defined(OS_MACOSX)
 #include <libkern/OSByteOrder.h>
-#elif defined(OS_OPENBSD)
+#elif defined(OS_OPENBSD) || defined(OS_FREEBSD)
 #include <sys/endian.h>
 #else
 #include <byteswap.h>
@@ -44,6 +44,8 @@
   return OSSwapInt64(x);
 #elif defined(OS_OPENBSD)
   return swap64(x);
+#elif defined(OS_FREEBSD)
+  return bswap64(x);
 #else
   return bswap_64(x);
 #endif
