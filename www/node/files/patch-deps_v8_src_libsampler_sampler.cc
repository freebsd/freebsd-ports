--- deps/v8/src/libsampler/sampler.cc.orig	2017-10-24 19:40:19 UTC
+++ deps/v8/src/libsampler/sampler.cc
@@ -506,9 +506,9 @@ void SignalHandler::FillRegisterState(void* context, R
   state->sp = reinterpret_cast<void*>(mcontext.mc_rsp);
   state->fp = reinterpret_cast<void*>(mcontext.mc_rbp);
 #elif V8_HOST_ARCH_ARM
-  state->pc = reinterpret_cast<void*>(mcontext.mc_r15);
-  state->sp = reinterpret_cast<void*>(mcontext.mc_r13);
-  state->fp = reinterpret_cast<void*>(mcontext.mc_r11);
+  state->pc = reinterpret_cast<void*>(mcontext.__gregs[_REG_PC]);
+  state->sp = reinterpret_cast<void*>(mcontext.__gregs[_REG_SP]);
+  state->fp = reinterpret_cast<void*>(mcontext.__gregs[_REG_FP]);
 #endif  // V8_HOST_ARCH_*
 #elif V8_OS_NETBSD
 #if V8_HOST_ARCH_IA32
