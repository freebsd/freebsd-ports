--- main/lock.c.orig	2013-09-09 19:56:02 UTC
+++ main/lock.c
@@ -691,10 +691,6 @@ int __ast_rwlock_init(int tracking, cons
 
 	pthread_rwlockattr_init(&attr);
 
-#ifdef HAVE_PTHREAD_RWLOCK_PREFER_WRITER_NP
-	pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NP);
-#endif
-
 	res = pthread_rwlock_init(&t->lock, &attr);
 	pthread_rwlockattr_destroy(&attr);
 	return res;
