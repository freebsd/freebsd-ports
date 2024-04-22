--- mDNSShared/PlatformCommon.h.orig	2024-02-05 20:49:19 UTC
+++ mDNSShared/PlatformCommon.h
@@ -18,6 +18,10 @@
 #ifndef __PLATFORM_COMMON_H
 #define __PLATFORM_COMMON_H
 
+#ifdef POSIX_BUILD
+#include <limits.h>
+#endif
+
 #ifndef NSEC_PER_SEC
     #define NSEC_PER_SEC 1000000000ull
 #endif
