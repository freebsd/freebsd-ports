--- deps/thpool/thpool.c.orig	2026-06-06 14:37:50 UTC
+++ deps/thpool/thpool.c
@@ -420,6 +420,8 @@ static void* thread_do(struct thread* thread_p) {
   prctl(PR_SET_NAME, thread_name);
 #elif defined(__APPLE__) && defined(__MACH__)
   pthread_setname_np(thread_name);
+#elif defined(__FreeBSD__)
+  pthread_set_name_np(pthread_self(), thread_name);
 #else
 	LOG_IF_EXISTS("warning", "thread_do(): pthread_setname_np is not supported on this system")
 #endif
