--- libdpe/lock.h.orig	2015-01-16 09:53:05.000000000 +0100
+++ libdpe/lock.h	2015-01-16 09:53:44.000000000 +0100
@@ -31,7 +31,7 @@
 #include <assert.h>
 #define rwlock_define(class,name)	class pthread_rwlock_t name
 #define RWLOCK_CALL(call) \
-	({ int _err = pthread_rwlock_ ## call; assert_perror(_err); })
+	({ int _err = pthread_rwlock_ ## call; assert(_err == 0); })
 #define rwlock_init(lock)	RWLOCK_CALL(init (&lock, NULL))
 #define rwlock_fini(lock)	RWLOCK_CALL(destroy (&lock))
 #define rwlock_rdlock(lock)	RWLOCK_CALL(rdlock (&lock))
