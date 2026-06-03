--- src/ucm/malloc/malloc_hook_stub.c.orig	2026-02-20 02:50:52 UTC
+++ src/ucm/malloc/malloc_hook_stub.c
@@ -0,0 +1,55 @@
+/*
+ * FreeBSD / non-glibc stub for UCX malloc hook support.
+ *
+ * This file provides the public API declared in malloc_hook.h, but does not
+ * attempt to install malloc hooks, relocate symbols, or tweak mallopt-style
+ * thresholds. Those mechanisms are glibc/ptmalloc-centric.
+ *
+ * The goal for now: link cleanly, behave safely, and fail gracefully when
+ * malloc hooking is actually required.
+ */
+
+#ifdef HAVE_CONFIG_H
+#  include "config.h"
+#endif
+
+#include "malloc_hook.h"
+
+#include <ucm/util/log.h>
+#include <ucs/sys/compiler.h>
+
+ucs_status_t ucm_malloc_install(int events)
+{
+    static int warned = 0;
+
+    /* We don't implement malloc hook installation on this platform (yet). */
+    if (!warned) {
+        ucm_debug("ucm_malloc_install(events=0x%x): stub (malloc hooks not supported on this build)",
+                  events);
+        warned = 1;
+    }
+
+    /*
+     * Conservative choice:
+     * - Return UNSUPPORTED so callers that *need* these hooks can fall back
+     *   or disable the feature.
+     *
+     * If you find a call site that expects OK unconditionally, we can make this
+     * conditional (e.g., return OK when events==0), but UNSUPPORTED is the honest
+     * default.
+     */
+    return (events == 0) ? UCS_OK : UCS_ERR_UNSUPPORTED;
+}
+
+void ucm_init_malloc_hook(void)
+{
+    /* No-op for stub. */
+}
+
+void ucm_malloc_state_reset(int default_mmap_thresh, int default_trim_thresh)
+{
+    (void)default_mmap_thresh;
+    (void)default_trim_thresh;
+
+    /* No-op for stub (no mallopt-style tuning here). */
+}
