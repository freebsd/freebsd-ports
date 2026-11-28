--- deps/thpool/thpool.c.orig	2025-04-21 14:51:40 UTC
+++ deps/thpool/thpool.c
@@ -436,6 +436,8 @@ static void* thread_do(struct thread* thread_p) {
   prctl(PR_SET_NAME, thread_name);
 #elif defined(__APPLE__) && defined(__MACH__)
   pthread_setname_np(thread_name);
+#elif defined(__FreeBSD__)
+  pthread_set_name_np(pthread_self(), thread_name);
 #else
 	LOG_IF_EXISTS("warning", "thread_do(): pthread_setname_np is not supported on this system")
 #endif
