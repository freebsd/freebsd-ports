--- third_party/chromium/src/base/sys_byteorder.h.org	2012-05-15 13:15:00.000000000 +0900
+++ third_party/chromium/src/base/sys_byteorder.h	2012-05-15 13:32:03.000000000 +0900
@@ -25,7 +25,7 @@
 #include <stdlib.h>
 #elif defined(OS_MACOSX)
 #include <libkern/OSByteOrder.h>
-#elif defined(OS_OPENBSD)
+#elif defined(OS_OPENBSD) || defined(OS_FREEBSD)
 #include <sys/endian.h>
 #else
 #include <byteswap.h>
@@ -42,6 +42,8 @@
   return OSSwapInt16(x);
 #elif defined(OS_OPENBSD)
   return swap16(x);
+#elif defined(OS_FREEBSD)
+  return bswap16(x);
 #else
   return bswap_16(x);
 #endif
@@ -53,6 +55,8 @@
   return OSSwapInt32(x);
 #elif defined(OS_OPENBSD)
   return swap32(x);
+#elif defined(OS_FREEBSD)
+  return bswap32(x);
 #else
   return bswap_32(x);
 #endif
@@ -63,7 +67,9 @@
 #elif defined(OS_MACOSX)
   return OSSwapInt64(x);
 #elif defined(OS_OPENBSD)
-  return swap64(x);
+  return swap64(x); 
+#elif defined(OS_FREEBSD)
+  return bswap64(x);
 #else
   return bswap_64(x);
 #endif
