--- content/renderer/devtools/v8_sampling_profiler.cc.orig	2016-05-11 19:02:21 UTC
+++ content/renderer/devtools/v8_sampling_profiler.cc
@@ -544,6 +544,10 @@ void V8SamplingThread::HandleProfilerSig
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
