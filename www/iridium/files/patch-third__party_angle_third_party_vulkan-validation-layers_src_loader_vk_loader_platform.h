--- third_party/angle/third_party/vulkan-validation-layers/src/loader/vk_loader_platform.h.orig	2018-07-19 21:07:44.888863000 +0200
+++ third_party/angle/third_party/vulkan-validation-layers/src/loader/vk_loader_platform.h	2018-07-19 21:08:10.994378000 +0200
@@ -31,7 +31,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
