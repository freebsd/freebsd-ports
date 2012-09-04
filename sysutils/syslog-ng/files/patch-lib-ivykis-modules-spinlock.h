--- lib/ivykis/modules/spinlock.h.orig	2012-08-19 09:22:52.000000000 -0700
+++ lib/ivykis/modules/spinlock.h	2012-09-04 07:23:18.148108582 -0700
@@ -25,7 +25,7 @@
 
 static inline void spin_init(spinlock_t *lock)
 {
-	pthread_spin_init(lock, PTHREAD_PROCESS_PRIVATE);
+	pthread_spin_init(lock, PTHREAD_PROCESS_SHARED);
 }
 
 static inline void spin_lock(spinlock_t *lock)
