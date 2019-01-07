--- third_party/angle/third_party/vulkan-validation-layers/src/layers/vk_loader_platform.h.orig	2018-12-12 23:03:04.000000000 +0100
+++ third_party/angle/third_party/vulkan-validation-layers/src/layers/vk_loader_platform.h	2018-12-16 00:53:28.074127000 +0100
@@ -31,7 +31,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
