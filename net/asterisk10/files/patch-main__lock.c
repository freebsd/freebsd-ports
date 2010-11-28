--- ./main/lock.c.orig	2010-11-06 15:00:15.000000000 +0100
+++ ./main/lock.c	2010-11-06 15:00:23.000000000 +0100
@@ -679,10 +679,6 @@
 
 	pthread_rwlockattr_init(&attr);
 
-#ifdef HAVE_PTHREAD_RWLOCK_PREFER_WRITER_NP
-	pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NP);
-#endif
-
 	res = pthread_rwlock_init(&t->lock, &attr);
 	pthread_rwlockattr_destroy(&attr);
 	return res;
