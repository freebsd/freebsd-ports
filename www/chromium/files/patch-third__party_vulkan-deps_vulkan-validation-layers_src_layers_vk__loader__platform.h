--- third_party/vulkan-deps/vulkan-validation-layers/src/layers/vk_loader_platform.h.orig	2021-04-14 18:43:14 UTC
+++ third_party/vulkan-deps/vulkan-validation-layers/src/layers/vk_loader_platform.h
@@ -33,7 +33,7 @@
 #undef NOMINMAX
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
