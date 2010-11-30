--- ./utils/extconf.c.orig	2010-11-12 16:49:46.000000000 +0100
+++ ./utils/extconf.c	2010-11-12 16:50:00.000000000 +0100
@@ -718,10 +718,6 @@
 
 	pthread_rwlockattr_init(&attr);
 
-#ifdef HAVE_PTHREAD_RWLOCK_PREFER_WRITER_NP
-	pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NP);
-#endif
-
 	return pthread_rwlock_init(prwlock, &attr);
 }
 
