--- core/OfficeUtils/src/zlib-1.2.11/gzguts.h.orig      2025-04-16 08:37:24.000000000 +0000
+++ core/OfficeUtils/src/zlib-1.2.11/gzguts.h   2025-06-19 20:31:01.755367000 +0000
@@ -33,6 +33,8 @@

 #ifdef _WIN32
 #  include <stddef.h>
+#else
+#  include <unistd.h>
 #endif

 #if defined(__TURBOC__) || defined(_MSC_VER) || defined(_WIN32)

