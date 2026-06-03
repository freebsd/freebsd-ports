--- src/pipewire/thread.h.orig	2026-03-16 11:54:17 UTC
+++ src/pipewire/thread.h
@@ -24,6 +24,11 @@ extern "C" {
  * \{
  */
 
+/* FreeBSD compat */
+#ifndef SCHED_RESET_ON_FORK
+#define SCHED_RESET_ON_FORK 0
+#endif
+
 SPA_DEPRECATED
 void pw_thread_utils_set(struct spa_thread_utils *impl);
 struct spa_thread_utils *pw_thread_utils_get(void);
