--- base/allocator/partition_allocator/spinning_mutex.cc.orig	2021-12-14 11:44:55 UTC
+++ base/allocator/partition_allocator/spinning_mutex.cc
@@ -22,6 +22,13 @@
 #include <unistd.h>
 #endif  // defined(PA_HAS_LINUX_KERNEL)
 
+#if defined(PA_HAS_FREEBSD_KERNEL)
+#include <errno.h>
+#include <sys/types.h>
+#include <sys/thr.h>
+#include <sys/umtx.h>
+#endif  // defined(PA_HAS_FREEBSD_KERNEL)
+
 #if !defined(PA_HAS_FAST_MUTEX)
 #include "base/threading/platform_thread.h"
 
@@ -43,7 +50,7 @@ namespace internal {
 
 #if defined(PA_HAS_FAST_MUTEX)
 
-#if defined(PA_HAS_LINUX_KERNEL)
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL)
 
 void SpinningMutex::FutexWait() {
   // Save and restore errno.
@@ -67,8 +74,13 @@ void SpinningMutex::FutexWait() {
   // |kLockedContended| anymore. Note that even without spurious wakeups, the
   // value of |state_| is not guaranteed when this returns, as another thread
   // may get the lock before we get to run.
+#if defined(PA_HAS_LINUX_KERNEL)
   int err = syscall(SYS_futex, &state_, FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
                     kLockedContended, nullptr, nullptr, 0);
+#elif defined(PA_HAS_FREEBSD_KERNEL)
+  int err = _umtx_op(&state_, UMTX_OP_WAIT_UINT_PRIVATE,
+		     kLockedContended, nullptr, nullptr);
+#endif
 
   if (err) {
     // These are programming error, check them.
@@ -80,8 +92,14 @@ void SpinningMutex::FutexWait() {
 
 void SpinningMutex::FutexWake() {
   int saved_errno = errno;
+#if defined(PA_HAS_LINUX_KERNEL)
   long retval = syscall(SYS_futex, &state_, FUTEX_WAKE | FUTEX_PRIVATE_FLAG,
                         1 /* wake up a single waiter */, nullptr, nullptr, 0);
+#elif defined(PA_HAS_FREEBSD_KERNEL)
+  long retval = _umtx_op(&state_, UMTX_OP_WAKE_PRIVATE,
+                         1 /* wake up a single waiter */, nullptr, nullptr);
+#endif
+		      
   PA_CHECK(retval != -1);
   errno = saved_errno;
 }
