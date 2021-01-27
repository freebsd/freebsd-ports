--- third_party/angle/third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2021-01-18 21:31:55 UTC
+++ third_party/angle/third_party/vulkan-loader/src/loader/vk_loader_platform.h
@@ -35,7 +35,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
