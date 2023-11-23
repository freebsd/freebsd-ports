--- src/3rdparty/chromium/base/synchronization/lock_impl.h.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/base/synchronization/lock_impl.h
@@ -104,6 +104,10 @@ void LockImpl::Unlock() {
 }
 
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
+#endif
 
 #if DCHECK_IS_ON()
 BASE_EXPORT void dcheck_trylock_result(int rv);
@@ -124,6 +128,9 @@ void LockImpl::Unlock() {
   dcheck_unlock_result(rv);
 #endif
 }
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic pop
+#endif
 #endif
 
 // This is an implementation used for AutoLock templated on the lock type.
