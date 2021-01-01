--- third_party/angle/third_party/vulkan-loader/src/loader/loader.c.orig	2020-02-03 21:54:58 UTC
+++ third_party/angle/third_party/vulkan-loader/src/loader/loader.c
@@ -238,7 +238,7 @@ void *loader_device_heap_realloc(const struct loader_d
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 
 static inline bool IsHighIntegrity() {
     return geteuid() != getuid() || getegid() != getgid();
