--- main/lock.c.orig	2020-07-09 15:39:17 UTC
+++ main/lock.c
@@ -689,9 +689,6 @@ int __ast_rwlock_init(int tracking, const char *filena
 #endif /* DEBUG_THREADS */
 
 	pthread_rwlockattr_init(&attr);
-#ifdef HAVE_PTHREAD_RWLOCK_PREFER_WRITER_NP
-	pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NP);
-#endif
 	res = pthread_rwlock_init(&t->lock, &attr);
 	pthread_rwlockattr_destroy(&attr);
 
