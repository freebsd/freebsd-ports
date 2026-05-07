--- src/palette/ConfigManager.cpp.orig	2026-05-07 08:43:50 UTC
+++ src/palette/ConfigManager.cpp
@@ -8,7 +8,11 @@
 #include <glob.h>
 #include <filesystem>
 #include <cstring>
+#if defined(__linux__)
 #include <linux/limits.h>
+#else
+#include <limits.h>
+#endif
 
 using namespace Hyprtoolkit;
 
