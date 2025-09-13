--- base/allocator/partition_allocator/src/partition_alloc/spinning_mutex.cc.orig	2025-09-11 13:19:19 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/spinning_mutex.cc
@@ -24,7 +24,16 @@
 #endif
 
 #if PA_CONFIG(HAS_LINUX_KERNEL)
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
 
@@ -97,8 +106,16 @@ PA_ALWAYS_INLINE long FutexSyscall(volatile void* ftx,
   int saved_errno = errno;
   errno = 0;
 
+#if defined(OS_FREEBSD)
+  long retval = _umtx_op(&state_, UMTX_OP_WAIT_UINT_PRIVATE,
+                    kLockedContended, nullptr, nullptr);
+#elif defined(OS_OPENBSD)
+  long retval = futex(reinterpret_cast<volatile unsigned int *>(&state_), FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
+                    kLockedContended, nullptr, nullptr);
+#else
   long retval = syscall(SYS_futex, ftx, op | FUTEX_PRIVATE_FLAG, value, nullptr,
                         nullptr, 0);
+#endif
   if (retval == -1) {
     // These are programming errors, check them.
     PA_DCHECK((errno != EPERM) || (errno != EACCES) || (errno != EINVAL) ||
