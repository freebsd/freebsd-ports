--- src/common/defaults.h.orig	2016-11-29 22:48:37 UTC
+++ src/common/defaults.h
@@ -366,6 +366,9 @@ size_t default_get_ust_uid_channel_subbu
  * pthread_attr_t pointer where the thread stack size is set to the soft stack
  * size limit.
  */
+#if defined(__FreeBSD__)
+#include <pthread.h>
+#endif
 LTTNG_HIDDEN
 pthread_attr_t *default_pthread_attr(void);
 
