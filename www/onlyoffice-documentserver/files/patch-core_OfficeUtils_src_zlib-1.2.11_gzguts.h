--- core/OfficeUtils/src/zlib-1.2.11/gzguts.h.orig      2025-04-16 08:37:24 UTC
+++ core/OfficeUtils/src/zlib-1.2.11/gzguts.h
@@ -33,6 +33,8 @@

 #ifdef _WIN32
 #  include <stddef.h>
+#else
+#  include <unistd.h>
 #endif

 #if defined(__TURBOC__) || defined(_MSC_VER) || defined(_WIN32)

