--- third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h
@@ -42,7 +42,7 @@
 #include "dlopen_fuchsia.h"
 #endif  // defined(__Fuchsia__)
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <unistd.h>
 // Note: The following file is for dynamic loading:
 #include <dlfcn.h>
@@ -102,7 +102,7 @@
 // Override layer information
 #define VK_OVERRIDE_LAYER_NAME "VK_LAYER_LUNARG_override"
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 /* Linux-specific common code: */
 
 // VK Library Filenames, Paths, etc.:
@@ -195,7 +195,7 @@ static inline char *loader_platform_executable_path(ch
 
     return buffer;
 }
-#elif defined(__Fuchsia__)
+#elif defined(__Fuchsia__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 static inline char *loader_platform_executable_path(char *buffer, size_t size) { return NULL; }
 #elif defined(__QNXNTO__)
 
