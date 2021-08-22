--- third_party/vulkan-deps/vulkan-loader/src/loader/loader.c.orig	2021-07-19 18:47:36 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/loader.c
@@ -253,7 +253,7 @@ void *loader_device_heap_realloc(const struct loader_d
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
 
 static inline bool IsHighIntegrity() {
     return geteuid() != getuid() || getegid() != getgid();
