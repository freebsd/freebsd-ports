--- third_party/perfetto/src/base/futex.cc.orig	2026-11-17 11:49:09 UTC
+++ third_party/perfetto/src/base/futex.cc
@@ -22,8 +22,13 @@
 
 #if PERFETTO_HAS_FUTEX()
 #include <errno.h>
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
+#include <sys/time.h>
+#include <sys/futex.h>
+#else
 #include <linux/futex.h>
 #include <linux/types.h>
+#endif
 #include <sys/syscall.h>
 #include <unistd.h>
 #endif
@@ -41,15 +46,24 @@ FutexWaitResult FutexWait(const uint32_t* word,
   // SYS_futex expects seconds and nanoseconds in two kernel-sized longs.
   // Use that layout directly because libc's timespec can use a wider time_t.
   // Even UINT32_MAX milliseconds fits in signed 32-bit seconds.
+#if !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
   struct KernelTimespec {
     __kernel_long_t tv_sec;
     __kernel_long_t tv_nsec;
   };
+#endif
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
+  const timespec timeout{
+      static_cast<time_t>(timeout_ms / 1000),
+      static_cast<long>((timeout_ms % 1000) * 1000000)};
+  const int ret = futex(reinterpret_cast<volatile unsigned int *>(&word), FUTEX_WAIT, expected_value, &timeout, nullptr);
+#else
   const KernelTimespec timeout{
       static_cast<__kernel_long_t>(timeout_ms / 1000),
       static_cast<__kernel_long_t>((timeout_ms % 1000) * 1000000)};
   const int ret = static_cast<int>(syscall(
       SYS_futex, word, FUTEX_WAIT, expected_value, &timeout, nullptr, 0));
+#endif
   if (ret == 0)
     return FutexWaitResult::kWoken;
 
@@ -68,8 +82,12 @@ FutexWaitResult FutexWait(const uint32_t* word,
 
 int FutexWake(const uint32_t* word, int max_waiters) {
   PERFETTO_DCHECK(max_waiters > 0);
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
+  const int ret = futex(reinterpret_cast<volatile unsigned int *>(&word), FUTEX_WAKE, max_waiters, nullptr, nullptr);
+#else
   const int ret = static_cast<int>(
       syscall(SYS_futex, word, FUTEX_WAKE, max_waiters, nullptr, nullptr, 0));
+#endif
   if (PERFETTO_UNLIKELY(ret < 0)) {
     PERFETTO_DPLOG("futex FUTEX_WAKE failed");
     return -1;
