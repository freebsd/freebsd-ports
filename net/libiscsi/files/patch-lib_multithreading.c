--- lib/multithreading.c.orig	2025-05-03 00:02:42 UTC
+++ lib/multithreading.c
@@ -154,6 +154,8 @@ iscsi_tid_t iscsi_mt_get_tid(void)
 #elif defined(SYS_gettid)
         pid_t tid = syscall(SYS_gettid);
         return tid;
+#elif defined(__FreeBSD__)
+	return pthread_getthreadid_np();
 #else
 #error "SYS_gettid unavailable on this system"
 #endif
