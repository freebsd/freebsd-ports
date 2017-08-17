--- src/3rdparty/chromium/content/renderer/devtools/v8_sampling_profiler.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/content/renderer/devtools/v8_sampling_profiler.cc
@@ -6,6 +6,7 @@
 
 #include <stdint.h>
 #include <string.h>
+#include <ucontext.h>
 
 #include "base/format_macros.h"
 #include "base/location.h"
@@ -544,6 +546,10 @@ void V8SamplingThread::HandleProfilerSignal(int signal
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
