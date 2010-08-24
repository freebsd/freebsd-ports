--- lib/FXThread.cpp.orig	2010-08-23 13:21:01.000000000 +0000
+++ lib/FXThread.cpp	2010-08-23 13:21:20.000000000 +0000
@@ -1182,7 +1182,7 @@
   // machine and mail it to: jeroen@fox-toolkit.com!!
   //FXTRACE((150,"sizeof(pthread_rwlock_t)=%d\n",sizeof(pthread_rwlock_t)));
   FXASSERT(sizeof(data)>=sizeof(pthread_rwlock_t));
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   pthread_rwlock_init((pthread_rwlock_t*)data,NULL);
 #else
   pthread_rwlockattr_t rwlockatt;
