--- base/profiler/stack_copier_signal.cc.orig	2020-03-03 18:53:47 UTC
+++ base/profiler/stack_copier_signal.cc
@@ -4,10 +4,16 @@
 
 #include "base/profiler/stack_copier_signal.h"
 
+#if defined(OS_LINUX)
 #include <linux/futex.h>
+#include <syscall.h>
+#elif defined(OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/thr.h>
+#include <sys/umtx.h>
+#endif
 #include <signal.h>
 #include <sys/ucontext.h>
-#include <syscall.h>
 
 #include <atomic>
 
@@ -35,8 +41,13 @@ class AsyncSafeWaitableEvent {
     // for a pthread mutex. So, also check the condition.
     while (true) {
       int res =
+#if defined(OS_LINUX)
           syscall(SYS_futex, futex_int_ptr(), FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
                   0, nullptr, nullptr, 0);
+#elif defined(OS_FREEBSD)
+          _umtx_op(futex_int_ptr(), UMTX_OP_WAIT_UINT_PRIVATE, 0, nullptr,
+                   nullptr);
+#endif
       if (futex_.load(std::memory_order_acquire) != 0)
         return true;
       if (res != 0)
@@ -46,8 +57,12 @@ class AsyncSafeWaitableEvent {
 
   void Signal() {
     futex_.store(1, std::memory_order_release);
+#if defined(OS_LINUX)
     syscall(SYS_futex, futex_int_ptr(), FUTEX_WAKE | FUTEX_PRIVATE_FLAG, 1,
             nullptr, nullptr, 0);
+#elif defined(OS_FREEBSD)
+    _umtx_op(futex_int_ptr(), UMTX_OP_WAKE_PRIVATE, 1, nullptr, nullptr);
+#endif
   }
 
  private:
@@ -201,11 +216,17 @@ bool StackCopierSignal::CopyStack(StackBuffer* stack_b
     if (!scoped_sigaction.succeeded())
       return false;
 
+#if defined(OS_LINUX)
     if (syscall(SYS_tgkill, getpid(), thread_delegate_->GetThreadId(),
                 SIGURG) != 0) {
       NOTREACHED();
       return false;
     }
+#elif defined(OS_FREEBSD)
+    if (thr_kill2(getpid(), thread_delegate_->GetThreadId(), SIGURG) != 0) {
+      return false;
+    }
+#endif
     bool finished_waiting = wait_event.Wait();
     TRACE_EVENT_END0(TRACE_DISABLED_BY_DEFAULT("cpu_profiler.debug"),
                      "StackCopierSignal copy stack");
