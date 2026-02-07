--- src/3rdparty/chromium/third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/vulkan-loader/src/loader/vk_loader_platform.h
@@ -353,7 +353,15 @@ static inline char *loader_platform_executable_path(ch
 
     return buffer;
 }
-#elif defined(__Fuchsia__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+    if ((buffer = getenv("CHROME_EXE_PATH")) != NULL)
+        return buffer;
+    else
+        buffer = "/usr/local/chrome/chrome";
+  return buffer;
+}
+#elif defined(__Fuchsia__)
 static inline char *loader_platform_executable_path(char *buffer, size_t size) { return NULL; }
 #elif defined(__QNX__)
 
