--- src/3rdparty/chromium/base/allocator/partition_allocator/spinning_mutex.cc.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/spinning_mutex.cc
@@ -18,7 +18,16 @@
 
 #if PA_CONFIG(HAS_LINUX_KERNEL)
 #include <errno.h>
+#if defined(OS_OPENBSD)
+#include <sys/time.h>
+#include <sys/futex.h>
+#elif defined(OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/thr.h>
+#include <sys/umtx.h>
+#else
 #include <linux/futex.h>
+#endif
 #include <sys/syscall.h>
 #include <unistd.h>
 #endif  // PA_CONFIG(HAS_LINUX_KERNEL)
@@ -107,8 +116,16 @@ void SpinningMutex::FutexWait() {
   // |kLockedContended| anymore. Note that even without spurious wakeups, the
   // value of |state_| is not guaranteed when this returns, as another thread
   // may get the lock before we get to run.
+#if defined(OS_FREEBSD)
+  int err = _umtx_op(&state_, UMTX_OP_WAIT_UINT_PRIVATE,
+                    kLockedContended, nullptr, nullptr);
+#elif defined(OS_OPENBSD)
+  int err = futex(reinterpret_cast<volatile unsigned int *>(&state_), FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
+                    kLockedContended, nullptr, nullptr);
+#else
   int err = syscall(SYS_futex, &state_, FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
                     kLockedContended, nullptr, nullptr, 0);
+#endif
 
   if (err) {
     // These are programming error, check them.
@@ -120,8 +137,16 @@ void SpinningMutex::FutexWait() {
 
 void SpinningMutex::FutexWake() {
   int saved_errno = errno;
+#if defined(OS_FREEBSD)
+  long retval = _umtx_op(&state_, UMTX_OP_WAKE_PRIVATE,
+                         1 /* wake up a single waiter */, nullptr, nullptr);
+#elif defined(OS_OPENBSD)
+  long retval = futex(reinterpret_cast<volatile unsigned int *>(&state_), FUTEX_WAKE | FUTEX_PRIVATE_FLAG,
+                        1 /* wake up a single waiter */, nullptr, nullptr);
+#else
   long retval = syscall(SYS_futex, &state_, FUTEX_WAKE | FUTEX_PRIVATE_FLAG,
                         1 /* wake up a single waiter */, nullptr, nullptr, 0);
+#endif
   PA_CHECK(retval != -1);
   errno = saved_errno;
 }
