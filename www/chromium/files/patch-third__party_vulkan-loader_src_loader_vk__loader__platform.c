--- third_party/vulkan-loader/src/loader/vk_loader_platform.c.orig	2026-11-19 12:25:27 UTC
+++ third_party/vulkan-loader/src/loader/vk_loader_platform.c
@@ -133,7 +133,29 @@ char *loader_platform_executable_path(const struct loa
 
     return buffer;
 }
-#elif defined(__Fuchsia__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
+char *loader_platform_executable_path(const struct loader_instance *inst, bool *oom) {
+    size_t size = 1024;
+    char *buffer = loader_instance_heap_calloc(inst, size, VK_SYSTEM_ALLOCATION_SCOPE_COMMAND);
+    if (NULL == buffer) {
+        *oom = true;
+        return NULL;
+    }
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
+    return buffer;
+}
+#elif defined(__Fuchsia__)
 char *loader_platform_executable_path(const struct loader_instance *inst, bool *oom) {
     (void)inst;
     (void)oom;
