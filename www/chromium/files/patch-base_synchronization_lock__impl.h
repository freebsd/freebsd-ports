--- base/synchronization/lock_impl.h.orig	2020-07-07 21:58:11 UTC
+++ base/synchronization/lock_impl.h
@@ -69,10 +69,13 @@ void LockImpl::Unlock() {
   ::ReleaseSRWLockExclusive(reinterpret_cast<PSRWLOCK>(&native_handle_));
 }
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
 void LockImpl::Unlock() {
   int rv = pthread_mutex_unlock(&native_handle_);
   DCHECK_EQ(rv, 0) << ". " << strerror(rv);
 }
+#pragma GCC diagnostic pop
 #endif
 
 // This is an implementation used for AutoLock templated on the lock type.
