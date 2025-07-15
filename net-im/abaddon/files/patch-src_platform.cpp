--- src/platform.cpp.orig	2025-07-11 20:03:35 UTC
+++ src/platform.cpp
@@ -93,7 +93,7 @@ std::string Platform::FindStateCacheFolder() {
     return ".";
 }
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 std::string Platform::FindResourceFolder() {
     static std::string found_path;
     static bool found = false;
