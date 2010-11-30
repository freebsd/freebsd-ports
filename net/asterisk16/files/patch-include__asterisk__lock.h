--- ./include/asterisk/lock.h.orig	2010-11-12 17:01:29.000000000 +0100
+++ ./include/asterisk/lock.h	2010-11-12 17:01:38.000000000 +0100
@@ -1049,10 +1049,6 @@
 	t->tracking = tracking;
 	pthread_rwlockattr_init(&attr);
 
-#ifdef HAVE_PTHREAD_RWLOCK_PREFER_WRITER_NP
-	pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NP);
-#endif
-
 	res = pthread_rwlock_init(&t->lock, &attr);
 	pthread_rwlockattr_destroy(&attr);
 	return res;
@@ -1801,10 +1797,6 @@
 
 	pthread_rwlockattr_init(&attr);
 
-#ifdef HAVE_PTHREAD_RWLOCK_PREFER_WRITER_NP
-	pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NP);
-#endif
-
 	res = pthread_rwlock_init(prwlock, &attr);
 	pthread_rwlockattr_destroy(&attr);
 	return res;
