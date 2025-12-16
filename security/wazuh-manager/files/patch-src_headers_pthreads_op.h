--- src/headers/pthreads_op.h	2025-09-23 06:59:40.000000000 -0700
+++ src/headers/pthreads_op.h	2025-10-13 00:48:19.635169000 -0700
@@ -25,6 +25,37 @@
 #define w_cond_signal(x) { int error = pthread_cond_signal(x); if (error) merror_exit("At pthread_cond_signal(): %s", strerror(error)); }
 #define w_cond_broadcast(x) { int error = pthread_cond_broadcast(x); if (error) merror_exit("At pthread_cond_broadcast(): %s", strerror(error)); }
 #define w_cond_destroy(x) { int error = pthread_cond_destroy(x); if (error) merror_exit("At pthread_cond_destroy(): %s", strerror(error)); }
+#if defined(__FreeBSD__)
+#define w_portable_rwlock_init(x, y) { \
+    if (portable_rwlock_init(x) != 0) \
+        merror_exit("At portable_rwlock_init(): failed to initialize rwlock"); \
+}
+
+#define w_portable_rwlock_rdlock(x) { \
+    if (portable_rwlock_rdlock(x) != 0) \
+        merror_exit("At portable_rwlock_rdlock(): failed to acquire read lock"); \
+}
+
+#define w_portable_rwlock_wrlock(x) { \
+    if (portable_rwlock_wrlock(x) != 0) \
+        merror_exit("At portable_rwlock_wrlock(): failed to acquire write lock"); \
+}
+
+#define w_portable_rwlock_unlock_read(x) { \
+    if (portable_rwlock_rdunlock(x) != 0) \
+        merror_exit("At portable_rwlock_rdunlock(): failed to release read lock"); \
+}
+
+#define w_portable_rwlock_unlock_write(x) { \
+    if (portable_rwlock_wrunlock(x) != 0) \
+        merror_exit("At portable_rwlock_wrunlock(): failed to release write lock"); \
+}
+
+#define w_portable_rwlock_destroy(x) { \
+    if (portable_rwlock_destroy(x) != 0) \
+        merror_exit("At portable_rwlock_destroy(): failed to destroy rwlock"); \
+}
+#endif
 #define w_rwlock_init(x, y) { int error = pthread_rwlock_init(x, y); if (error) merror_exit("At pthread_rwlock_init(): %s", strerror(error)); }
 #define w_rwlock_rdlock(x) { int error = pthread_rwlock_rdlock(x); if (error) merror_exit("At pthread_rwlock_rdlock(): %s", strerror(error)); }
 #define w_rwlock_wrlock(x) { int error = pthread_rwlock_wrlock(x); if (error) merror_exit("At pthread_rwlock_wrlock(): %s", strerror(error)); }
