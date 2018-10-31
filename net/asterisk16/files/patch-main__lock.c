--- main/lock.c.orig	2018-08-08 16:02:31 UTC
+++ main/lock.c
@@ -692,9 +692,6 @@ int __ast_rwlock_init(int tracking, const char *filena
 #endif /* DEBUG_THREADS */
 
 	pthread_rwlockattr_init(&attr);
-#ifdef HAVE_PTHREAD_RWLOCK_PREFER_WRITER_NP
-	pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NP);
-#endif
 	res = pthread_rwlock_init(&t->lock, &attr);
 	pthread_rwlockattr_destroy(&attr);
 
