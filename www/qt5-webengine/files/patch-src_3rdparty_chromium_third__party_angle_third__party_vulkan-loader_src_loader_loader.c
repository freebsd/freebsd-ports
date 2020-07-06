--- src/3rdparty/chromium/third_party/angle/third_party/vulkan-loader/src/loader/loader.c.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/third_party/angle/third_party/vulkan-loader/src/loader/loader.c
@@ -229,7 +229,7 @@ void *loader_device_heap_realloc(const struct loader_d
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 
 static inline bool IsHighIntegrity() {
     return geteuid() != getuid() || getegid() != getgid();
