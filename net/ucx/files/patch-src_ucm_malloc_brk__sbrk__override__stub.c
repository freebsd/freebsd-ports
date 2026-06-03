--- src/ucm/malloc/brk_sbrk_override_stub.c.orig	2026-02-20 03:25:07 UTC
+++ src/ucm/malloc/brk_sbrk_override_stub.c
@@ -0,0 +1,25 @@
+#include <errno.h>
+#include <stdint.h>
+#include <unistd.h>
+
+/*
+ * Stubs for platforms/builds where we don't implement brk/sbrk overriding.
+ * Fail gracefully so callers can fall back or treat as unsupported.
+ *
+ * Marked weak so a real implementation (if later added) can override it.
+ */
+__attribute__((weak))
+int ucm_override_brk(void *addr)
+{
+    (void)addr;
+    errno = ENOSYS;
+    return -1;
+}
+
+__attribute__((weak))
+void *ucm_override_sbrk(intptr_t increment)
+{
+    (void)increment;
+    errno = ENOSYS;
+    return (void*)-1;
+}
