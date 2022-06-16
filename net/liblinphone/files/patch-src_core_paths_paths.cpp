--- src/core/paths/paths.cpp.orig	2022-06-16 10:38:29 UTC
+++ src/core/paths/paths.cpp
@@ -26,7 +26,7 @@
 	#include "paths-android.h"
 #elif defined(_WIN32)
 	#include "paths-windows.h"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	#include "paths-linux.h"
 #else
 	#error "Unsupported system."
