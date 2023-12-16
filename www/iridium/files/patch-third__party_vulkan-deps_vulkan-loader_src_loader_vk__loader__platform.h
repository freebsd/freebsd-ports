--- third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h.orig	2023-11-22 14:00:11 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/vk_loader_platform.h
@@ -312,7 +312,15 @@ static inline char *loader_platform_executable_path(ch
 
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
 #elif defined(__QNX__)
 
