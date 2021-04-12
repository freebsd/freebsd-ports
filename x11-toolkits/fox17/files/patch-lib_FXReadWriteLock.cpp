pthread_rwlockattr_setkind_np() is not implemented on FreeBSD. This function
was contained in an ifdef in version 1.7.75. The release notes for 1.7.76 only
state that not all systems have this function, but the supposed fix is a
regression on FreeBSD.

--- lib/FXReadWriteLock.cpp.orig	2021-04-02 00:40:37 UTC
+++ lib/FXReadWriteLock.cpp
@@ -70,7 +70,9 @@ FXReadWriteLock::FXReadWriteLock(){
   FXASSERT_STATIC(sizeof(data)>=sizeof(pthread_rwlock_t));
   pthread_rwlockattr_t rwlockatt;
   pthread_rwlockattr_init(&rwlockatt);
+#if defined(__linux__)
   pthread_rwlockattr_setkind_np(&rwlockatt,PTHREAD_RWLOCK_PREFER_WRITER_NP);
+#endif
   pthread_rwlock_init((pthread_rwlock_t*)data,&rwlockatt);
   pthread_rwlockattr_destroy(&rwlockatt);
 #else
