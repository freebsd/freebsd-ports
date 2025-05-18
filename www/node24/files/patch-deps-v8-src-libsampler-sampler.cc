--- deps/v8/src/libsampler/sampler.cc.orig	2025-05-06 12:36:30 UTC
+++ deps/v8/src/libsampler/sampler.cc
@@ -520,6 +520,10 @@ void SignalHandler::FillRegisterState(void* context, R
   state->pc = reinterpret_cast<void*>(mcontext.__gregs[_REG_PC]);
   state->sp = reinterpret_cast<void*>(mcontext.__gregs[_REG_SP]);
   state->fp = reinterpret_cast<void*>(mcontext.__gregs[_REG_FP]);
+#elif V8_TARGET_ARCH_PPC64
+  state->pc = reinterpret_cast<void*>(mcontext.mc_srr0);
+  state->sp = reinterpret_cast<void*>(mcontext.mc_frame[1]);
+  state->fp = reinterpret_cast<void*>(mcontext.mc_frame[31]);
 #endif  // V8_HOST_ARCH_*
 #elif V8_OS_NETBSD
 #if V8_HOST_ARCH_IA32
