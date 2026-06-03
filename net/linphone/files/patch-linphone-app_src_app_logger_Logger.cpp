--- linphone-app/src/app/logger/Logger.cpp.orig	2025-12-26 08:13:47 UTC
+++ linphone-app/src/app/logger/Logger.cpp
@@ -34,7 +34,7 @@
 
 // =============================================================================
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
   #define BLUE "\x1B[1;34m"
   #define YELLOW "\x1B[1;33m"
   #define GREEN "\x1B[1;32m"
