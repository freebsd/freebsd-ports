--- third_party/vulkan-validation-layers/src/loader/vk_loader_platform.h.orig	2017-08-02 15:08:43.821225000 +0200
+++ third_party/vulkan-validation-layers/src/loader/vk_loader_platform.h	2017-08-02 15:09:07.938907000 +0200
@@ -30,7 +30,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
