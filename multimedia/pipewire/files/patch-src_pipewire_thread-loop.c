--- src/pipewire/thread-loop.c.orig	2021-06-28 13:32:38 UTC
+++ src/pipewire/thread-loop.c
@@ -37,8 +37,14 @@
 #define pw_thread_loop_events_destroy(o)	pw_thread_loop_events_emit(o, destroy, 0)
 
 #ifdef __FreeBSD__
-#include <pthread_np.h>
-#define pthread_setname_np pthread_set_name_np
+#include <sys/param.h>
+#if __FreeBSD_version < 1202000
+int pthread_setname_np(pthread_t thread, const char *name)
+{
+	pthread_set_name_np(thread, name);
+	return 0;
+}
+#endif
 #endif
 
 /** \cond */
