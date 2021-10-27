--- base/profiler/register_context.h.orig	2021-09-14 01:51:47 UTC
+++ base/profiler/register_context.h
@@ -17,7 +17,7 @@
 #include <windows.h>
 #elif defined(OS_APPLE)
 #include <mach/machine/thread_status.h>
-#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/ucontext.h>
 #endif
 
@@ -209,6 +209,48 @@ inline uintptr_t& RegisterContextInstructionPointer(mc
 }
 
 #endif  // #if defined(ARCH_CPU_ARM_FAMILY) && defined(ARCH_CPU_32_BITS)
+
+#elif defined(OS_FREEBSD)
+
+using RegisterContext = mcontext_t;
+
+#if defined(ARCH_CPU_X86_64)
+inline uintptr_t& RegisterContextStackPointer(mcontext_t* context) {
+  return AsUintPtr(&context->mc_rsp);
+}
+
+inline uintptr_t& RegisterContextFramePointer(mcontext_t* context) {
+  return AsUintPtr(&context->mc_rbp);
+}
+
+inline uintptr_t& RegisterContextInstructionPointer(mcontext_t* context) {
+  return AsUintPtr(&context->mc_rip);
+}
+#elif defined(ARCH_CPU_X86)
+inline uintptr_t& RegisterContextStackPointer(mcontext_t* context) {
+  return AsUintPtr(&context->mc_esp);
+}
+
+inline uintptr_t& RegisterContextFramePointer(mcontext_t* context) {
+  return AsUintPtr(&context->mc_ebp);
+}
+
+inline uintptr_t& RegisterContextInstructionPointer(mcontext_t* context) {
+  return AsUintPtr(&context->mc_eip);
+}
+#elif defined(ARCH_CPU_ARM64)
+inline uintptr_t& RegisterContextStackPointer(mcontext_t* context) {
+  return AsUintPtr(&context->mc_gpregs.gp_sp);
+}
+
+inline uintptr_t& RegisterContextFramePointer(mcontext_t* context) {
+  return AsUintPtr(&context->mc_gpregs.gp_x[29]);
+}
+
+inline uintptr_t& RegisterContextInstructionPointer(mcontext_t* context) {
+  return AsUintPtr(&context->mc_gpregs.gp_elr);
+}
+#endif
 
 #else  // #if defined(OS_WIN)
 
