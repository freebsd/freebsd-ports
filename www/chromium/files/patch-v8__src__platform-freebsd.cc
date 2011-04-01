--- v8/src/platform-freebsd.cc.orig	2011-03-15 05:43:39.000000000 +0200
+++ v8/src/platform-freebsd.cc	2011-03-15 05:52:01.000000000 +0200
@@ -53,6 +53,7 @@
 #include "v8.h"
 
 #include "platform.h"
+#include "top.h"
 #include "vm-state-inl.h"
 
 
@@ -526,6 +527,16 @@
     return result;
   }
 
+  virtual bool TryLock() {
+    int result = pthread_mutex_trylock(&mutex_);
+    // Return false if the lock is busy and locking failed.
+    if (result == EBUSY) {
+      return false;
+    }
+    ASSERT(result == 0);  // Verify no other errors.
+    return true;
+  }
+
  private:
   pthread_mutex_t mutex_;   // Pthread mutex for POSIX platforms.
 };
@@ -595,39 +606,41 @@
 #ifdef ENABLE_LOGGING_AND_PROFILING
 
 static Sampler* active_sampler_ = NULL;
+static pthread_t vm_tid_ = 0;
 
 static void ProfilerSignalHandler(int signal, siginfo_t* info, void* context) {
   USE(info);
   if (signal != SIGPROF) return;
-  if (active_sampler_ == NULL) return;
 
-  TickSample sample;
+  if (active_sampler_ == NULL || !active_sampler_->IsActive()) return;
+  if (vm_tid_ != pthread_self()) return;
 
-  // We always sample the VM state.
-  sample.state = VMState::current_state();
+  TickSample sample_obj;
+  TickSample* sample = CpuProfiler::TickSampleEvent();
+  if (sample == NULL) sample = &sample_obj;
+
+  // Extracting the sample from the context is extremely machine dependent.
+  ucontext_t* ucontext = reinterpret_cast<ucontext_t*>(context);
+  mcontext_t& mcontext = ucontext->uc_mcontext;
+  sample->state = Top::current_vm_state();
 
-  // If profiling, we extract the current pc and sp.
-  if (active_sampler_->IsProfiling()) {
-    // Extracting the sample from the context is extremely machine dependent.
-    ucontext_t* ucontext = reinterpret_cast<ucontext_t*>(context);
-    mcontext_t& mcontext = ucontext->uc_mcontext;
 #if V8_HOST_ARCH_IA32
-    sample.pc = reinterpret_cast<Address>(mcontext.mc_eip);
-    sample.sp = reinterpret_cast<Address>(mcontext.mc_esp);
-    sample.fp = reinterpret_cast<Address>(mcontext.mc_ebp);
+  sample->pc = reinterpret_cast<Address>(mcontext.mc_eip);
+  sample->sp = reinterpret_cast<Address>(mcontext.mc_esp);
+  sample->fp = reinterpret_cast<Address>(mcontext.mc_ebp);
 #elif V8_HOST_ARCH_X64
-    sample.pc = reinterpret_cast<Address>(mcontext.mc_rip);
-    sample.sp = reinterpret_cast<Address>(mcontext.mc_rsp);
-    sample.fp = reinterpret_cast<Address>(mcontext.mc_rbp);
+  sample->pc = reinterpret_cast<Address>(mcontext.mc_rip);
+  sample->sp = reinterpret_cast<Address>(mcontext.mc_rsp);
+  sample->fp = reinterpret_cast<Address>(mcontext.mc_rbp);
 #elif V8_HOST_ARCH_ARM
-    sample.pc = reinterpret_cast<Address>(mcontext.mc_r15);
-    sample.sp = reinterpret_cast<Address>(mcontext.mc_r13);
-    sample.fp = reinterpret_cast<Address>(mcontext.mc_r11);
+  sample->pc = reinterpret_cast<Address>(mcontext.mc_r15);
+  sample->sp = reinterpret_cast<Address>(mcontext.mc_r13);
+  sample->fp = reinterpret_cast<Address>(mcontext.mc_r11);
+#else
+  UNIMPLEMENTED();
 #endif
-    active_sampler_->SampleStack(&sample);
-  }
-
-  active_sampler_->Tick(&sample);
+  active_sampler_->SampleStack(sample);
+  active_sampler_->Tick(sample);
 }
 
 
