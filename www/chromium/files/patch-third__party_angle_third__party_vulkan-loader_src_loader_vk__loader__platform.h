--- third_party/angle/third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2018-12-15 15:17:52.636531000 +0100
+++ third_party/angle/third_party/vulkan-loader/src/loader/vk_loader_platform.h	2018-12-15 15:18:37.634423000 +0100
@@ -31,7 +31,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
