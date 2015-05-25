--- content/renderer/devtools/v8_sampling_profiler.cc.orig	2015-05-21 09:58:46.394686000 -0400
+++ content/renderer/devtools/v8_sampling_profiler.cc	2015-05-21 10:11:21.858314000 -0400
@@ -534,6 +534,10 @@
   state.pc = reinterpret_cast<void*>(mcontext->__ss.REG_64_32(__rip, __eip));
   state.sp = reinterpret_cast<void*>(mcontext->__ss.REG_64_32(__rsp, __esp));
   state.fp = reinterpret_cast<void*>(mcontext->__ss.REG_64_32(__rbp, __ebp));
+#elif defined(OS_FREEBSD)
+  state.pc = reinterpret_cast<void*>(mcontext.REG_64_32(mc_rip, mc_eip));
+  state.sp = reinterpret_cast<void*>(mcontext.REG_64_32(mc_rsp, mc_esp));
+  state.fp = reinterpret_cast<void*>(mcontext.REG_64_32(mc_rbp, mc_ebp));
 #else
   state.pc =
       reinterpret_cast<void*>(mcontext.gregs[REG_64_32(REG_RIP, REG_EIP)]);
