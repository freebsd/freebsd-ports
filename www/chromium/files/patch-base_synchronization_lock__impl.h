--- base/synchronization/lock_impl.h.orig	2021-12-14 11:44:55 UTC
+++ base/synchronization/lock_impl.h
@@ -107,6 +107,8 @@ void LockImpl::Unlock() {
 }
 
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
 
 BASE_EXPORT std::string SystemErrorCodeToString(int error_code);
 
@@ -121,6 +123,7 @@ void LockImpl::Unlock() {
   int rv = pthread_mutex_unlock(&native_handle_);
   DCHECK_EQ(rv, 0) << ". " << strerror(rv);
 }
+#pragma GCC diagnostic pop
 #endif
 
 // This is an implementation used for AutoLock templated on the lock type.
