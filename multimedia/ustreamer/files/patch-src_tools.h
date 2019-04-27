--- src/tools.h.orig	2019-04-27 06:12:11 UTC
+++ src/tools.h
@@ -36,6 +36,13 @@
 #include <sys/ioctl.h>
 #include <sys/syscall.h>
 
+#ifndef CLOCK_MONOTONIC_RAW
+# ifdef CLOCK_MONOTONIC_FAST
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC_FAST
+# else
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+# endif
+#endif
 
 #define A_THREAD_CREATE(_tid, _func, _arg)	assert(!pthread_create(_tid, NULL, _func, _arg))
 #define A_THREAD_JOIN(_tid)					assert(!pthread_join(_tid, NULL))
@@ -106,5 +113,9 @@ INLINE long double get_now_real(void) {
 }
 
 INLINE pid_t get_thread_id(void) {
+#if defined(__FreeBSD__)
+	return pthread_getthreadid_np();
+#else
 	return syscall(SYS_gettid);
+#endif
 }
