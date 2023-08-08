--- src/core/paths/paths.cpp.orig	2023-03-17 13:29:37 UTC
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
