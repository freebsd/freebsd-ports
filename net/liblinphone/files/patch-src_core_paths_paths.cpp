--- src/core/paths/paths.cpp.orig	2025-03-20 22:21:32 UTC
+++ src/core/paths/paths.cpp
@@ -27,7 +27,7 @@
 #include "paths-android.h"
 #elif defined(_WIN32)
 #include "paths-windows.h"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "paths-linux.h"
 #else
 #error "Unsupported system."
