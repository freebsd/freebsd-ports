--- third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h.orig	2023-01-17 19:19:00 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h
@@ -294,7 +294,15 @@ static inline char *loader_platform_executable_path(ch
 
     return buffer;
 }
-#elif defined(__Fuchsia__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+    if ((buffer = getenv("IRIDIUM_EXE_PATH")) != NULL)
+        return buffer;
+    else
+        buffer = "/usr/local/iridium/iridium";
+  return buffer;
+}
+#elif defined(__Fuchsia__)
 static inline char *loader_platform_executable_path(char *buffer, size_t size) { return NULL; }
 #elif defined(__QNXNTO__)
 
