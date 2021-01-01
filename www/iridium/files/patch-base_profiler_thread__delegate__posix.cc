--- base/profiler/thread_delegate_posix.cc.orig	2020-04-10 00:37:03 UTC
+++ base/profiler/thread_delegate_posix.cc
@@ -4,6 +4,10 @@
 
 #include <pthread.h>
 
+#if defined(OS_FREEBSD)
+#include <pthread_np.h>
+#endif
+
 #include "base/process/process_handle.h"
 #include "base/profiler/thread_delegate_posix.h"
 #include "base/stl_util.h"
@@ -17,7 +21,12 @@ namespace {
 uintptr_t GetThreadStackBaseAddressImpl(
     SamplingProfilerThreadToken thread_token) {
   pthread_attr_t attr;
+#if defined(OS_FREEBSDD)
+  pthread_attr_init(&attr);
+  pthread_attr_get_np(thread_token.pthread_id, &attr);
+#elif defined(OS_LINUX)
   pthread_getattr_np(thread_token.pthread_id, &attr);
+#endif
   // See crbug.com/617730 for limitations of this approach on Linux.
   void* address;
   size_t size;
@@ -103,6 +112,15 @@ std::vector<uintptr_t*> ThreadDelegatePosix::GetRegist
   return {
       // Return the set of callee-save registers per the x86-64 System V ABI
       // section 3.2.1, plus the stack pointer.
+#if defined(OS_FREEBSD)
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_rbp),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_rbx),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_r12),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_r13),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_r14),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_r15),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_rsp),
+#else
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_RBP]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_RBX]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_R12]),
@@ -110,6 +128,7 @@ std::vector<uintptr_t*> ThreadDelegatePosix::GetRegist
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_R14]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_R15]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_RSP]),
+#endif
   };
 #else  // #if defined(ARCH_CPU_ARM_FAMILY) && defined(ARCH_CPU_32_BITS)
   // Unimplemented for other architectures.
