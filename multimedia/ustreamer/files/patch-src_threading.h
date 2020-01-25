--- src/threading.h.orig	2020-01-19 14:23:41 UTC
+++ src/threading.h
@@ -19,6 +19,7 @@
 #                                                                            #
 *****************************************************************************/
 
+#undef WITH_PTHREAD_NP https://github.com/pikvm/ustreamer/issues/12
 
 #pragma once
 
@@ -102,7 +103,7 @@ INLINE void thread_get_name(char *name) { // Always re
 #	endif
 	if (retval < 0) {
 #endif
-		assert(snprintf(name, MAX_THREAD_NAME, "tid=%d", (pid_t)syscall(SYS_gettid)) > 0);
+		assert(snprintf(name, MAX_THREAD_NAME, "tid=%d", (pid_t)syscall(SYS_thr_self)) > 0);
 #ifdef WITH_PTHREAD_NP
 	}
 #endif
