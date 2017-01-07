--- src/pj_mutex.c.orig	2016-08-29 18:47:58 UTC
+++ src/pj_mutex.c
@@ -124,7 +124,7 @@ void pj_acquire_lock()
         pthread_mutex_lock( &pj_precreated_lock);
 
         pthread_mutexattr_init(&mutex_attr);
-#ifdef HAVE_PTHREAD_MUTEX_RECURSIVE
+#if defined(HAVE_PTHREAD_MUTEX_RECURSIVE) || defined(__FreeBSD__)
         pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
 #else
         pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE_NP);
