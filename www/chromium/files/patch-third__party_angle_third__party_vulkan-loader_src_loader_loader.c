--- third_party/angle/third_party/vulkan-loader/src/loader/loader.c.orig	2018-12-15 15:11:13.525509000 +0100
+++ third_party/angle/third_party/vulkan-loader/src/loader/loader.c	2018-12-15 15:12:11.085519000 +0100
@@ -215,7 +215,7 @@
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 
 static inline char *loader_getenv(const char *name, const struct loader_instance *inst) {
     // No allocation of memory necessary for Linux, but we should at least touch
