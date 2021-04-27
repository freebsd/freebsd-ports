--- base/allocator/partition_allocator/spinning_mutex.h.orig	2021-04-14 18:40:48 UTC
+++ base/allocator/partition_allocator/spinning_mutex.h
@@ -22,7 +22,11 @@
 #define PA_HAS_LINUX_KERNEL
 #endif
 
-#if defined(PA_HAS_LINUX_KERNEL) || defined(OS_WIN)
+#if defined(OS_FREEBSD)
+#define PA_HAS_FREEBSD_KERNEL
+#endif
+
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL) || defined(OS_WIN)
 #define PA_HAS_SPINNING_MUTEX
 #endif
 
@@ -66,7 +70,7 @@ class LOCKABLE BASE_EXPORT SpinningMutex {
   // as the slow path has better characteristics than SpinLocks's.
   static constexpr int kSpinCount = 1000;
 
-#if defined(PA_HAS_LINUX_KERNEL)
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL)
   void FutexWait();
   void FutexWake();
 
@@ -111,7 +115,7 @@ ALWAYS_INLINE void SpinningMutex::Acquire() {
 
 inline constexpr SpinningMutex::SpinningMutex() = default;
 
-#if defined(PA_HAS_LINUX_KERNEL)
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL)
 
 ALWAYS_INLINE bool SpinningMutex::Try() {
   int expected = kUnlocked;
