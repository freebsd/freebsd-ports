--- deps/thpool/thpool.c.orig	2025-05-26 05:26:53 UTC
+++ deps/thpool/thpool.c
@@ -7,6 +7,9 @@
 #include <assert.h>
 #include <errno.h>
 #include <pthread.h>
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
 #include <stdatomic.h>
 #include <stdbool.h>
 #include <stdio.h>
@@ -651,6 +654,8 @@ static void *thread_do(redisearch_thpool_t *thpool_p) 
   prctl(PR_SET_NAME, thread_name);
 #elif defined(__APPLE__) && defined(__MACH__)
   pthread_setname_np(thread_name);
+#elif defined(__FreeBSD__)
+  pthread_set_name_np(pthread_self(), thread_name);
 #else
   LOG_IF_EXISTS(
       "warning",
