--- third_party/angle/third_party/vulkan-validation-layers/src/loader/loader.c.orig	2018-07-19 21:08:23.127507000 +0200
+++ third_party/angle/third_party/vulkan-validation-layers/src/loader/loader.c	2018-07-19 21:08:38.418461000 +0200
@@ -208,7 +208,7 @@
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 
 static inline char *loader_getenv(const char *name, const struct loader_instance *inst) {
     // No allocation of memory necessary for Linux, but we should at least touch
