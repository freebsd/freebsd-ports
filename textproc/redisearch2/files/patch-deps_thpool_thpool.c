--- deps/thpool/thpool.c.orig	2024-09-12 09:26:06 UTC
+++ deps/thpool/thpool.c
@@ -651,6 +651,8 @@ static void *thread_do(redisearch_thpool_t *thpool_p) 
   prctl(PR_SET_NAME, thread_name);
 #elif defined(__APPLE__) && defined(__MACH__)
   pthread_setname_np(thread_name);
+#elif defined(__FreeBSD__)
+  pthread_set_name_np(pthread_self(), thread_name);
 #else
   LOG_IF_EXISTS(
       "warning",
