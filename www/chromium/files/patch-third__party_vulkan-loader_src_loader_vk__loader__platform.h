--- third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2026-09-25 15:26:43 UTC
+++ third_party/vulkan-loader/src/loader/vk_loader_platform.h
@@ -29,6 +29,7 @@
 #if defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/select.h>
+#include <sys/param.h>
 #endif
 
 #include <assert.h>
@@ -361,7 +362,23 @@ static inline char *loader_platform_executable_path(ch
 
     return buffer;
 }
-#elif defined(__Fuchsia__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+#if (OpenBSD >= 202610)
+    char execpath[PATH_MAX];
+    if (getexecpath(execpath, sizeof(execpath)) != 0) {
+        return NULL;
+    }
+    *buffer = execpath;
+#else
+    if ((buffer = getenv("CHROME_EXE_PATH")) != NULL)
+        return buffer;
+    else
+        buffer = "/usr/local/chrome/chrome";
+#endif
+  return buffer;
+}
+#elif defined(__Fuchsia__)
 static inline char *loader_platform_executable_path(char *buffer, size_t size) { return NULL; }
 #elif defined(__QNX__)
 
