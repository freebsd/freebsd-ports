--- src/3rdparty/chromium/base/allocator/partition_allocator/spinning_mutex.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/spinning_mutex.h
@@ -114,7 +114,7 @@ class LOCKABLE BASE_EXPORT SpinningMutex {
 
 #if defined(PA_HAS_FAST_MUTEX)
 
-#if defined(PA_HAS_LINUX_KERNEL)
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL)
   void FutexWait();
   void FutexWake();
 
@@ -166,7 +166,7 @@ inline constexpr SpinningMutex::SpinningMutex() = defa
 
 #if defined(PA_HAS_FAST_MUTEX)
 
-#if defined(PA_HAS_LINUX_KERNEL)
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL)
 
 ALWAYS_INLINE bool SpinningMutex::Try() {
   // Using the weak variant of compare_exchange(), which may fail spuriously. On
