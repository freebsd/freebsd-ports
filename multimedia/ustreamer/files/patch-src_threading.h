--- src/threading.h.orig	2019-10-12 07:24:29 UTC
+++ src/threading.h
@@ -102,7 +102,7 @@ INLINE void thread_get_name(char *name) { // Always re
 #	endif
 	if (retval < 0) {
 #endif
-		assert(snprintf(name, MAX_THREAD_NAME, "tid=%d", (pid_t)syscall(SYS_gettid)) > 0);
+		assert(snprintf(name, MAX_THREAD_NAME, "tid=%d", (pid_t)syscall(SYS_thr_self)) > 0);
 #ifdef WITH_PTHREAD_NP
 	}
 #endif
