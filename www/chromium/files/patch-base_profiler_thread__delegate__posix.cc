--- base/profiler/thread_delegate_posix.cc.orig	2020-03-03 18:53:47 UTC
+++ base/profiler/thread_delegate_posix.cc
@@ -3,6 +3,9 @@
 // found in the LICENSE file.
 
 #include <pthread.h>
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
 
 #include "base/process/process_handle.h"
 #include "base/profiler/thread_delegate_posix.h"
@@ -17,12 +20,20 @@ namespace {
 uintptr_t GetThreadStackBaseAddressImpl(
     SamplingProfilerThreadToken thread_token) {
   pthread_attr_t attr;
+#if defined(OS_FREEBSD)
+  pthread_attr_init(&attr);
+  pthread_attr_get_np(thread_token.pthread_id, &attr);
+#elif defined(OS_LINUX)
   pthread_getattr_np(thread_token.pthread_id, &attr);
+#endif
   // See crbug.com/617730 for limitations of this approach on Linux.
   void* address;
   size_t size;
   pthread_attr_getstack(&attr, &address, &size);
   const uintptr_t base_address = reinterpret_cast<uintptr_t>(address) + size;
+#if defined(OS_FREEBSD)
+  pthread_attr_destroy(&attr);
+#endif
   return base_address;
 }
 
@@ -88,11 +99,19 @@ std::vector<uintptr_t*> ThreadDelegatePosix::GetRegist
   for (size_t i = 19; i <= 29; ++i)
     registers.push_back(reinterpret_cast<uintptr_t*>(&thread_context->regs[i]));
   return registers;
-#elif defined(ARCH_CPU_X86_64)  // #if defined(ARCH_CPU_ARM_FAMILY) &&
-                                // defined(ARCH_CPU_32_BITS)
+#elif defined(ARCH_CPU_X86_64)
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
@@ -100,6 +119,7 @@ std::vector<uintptr_t*> ThreadDelegatePosix::GetRegist
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_R14]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_R15]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_RSP]),
+#endif
   };
 #else  // #if defined(ARCH_CPU_ARM_FAMILY) && defined(ARCH_CPU_32_BITS)
   // Unimplemented for other architectures.
