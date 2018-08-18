--- content/browser/child_process_launcher_helper_linux.cc.orig	2018-05-09 21:05:48.000000000 +0200
+++ content/browser/child_process_launcher_helper_linux.cc	2018-08-16 10:43:09.493456000 +0200
@@ -18,7 +18,9 @@
 #include "content/public/common/content_switches.h"
 #include "content/public/common/result_codes.h"
 #include "content/public/common/sandboxed_process_launcher_delegate.h"
+#if !defined(OS_BSD)
 #include "content/public/common/zygote_handle.h"
+#endif
 #include "gpu/config/gpu_switches.h"
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
 
@@ -71,6 +73,7 @@
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !defined(OS_BSD)
   ZygoteHandle zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? nullptr
@@ -84,7 +87,6 @@
         GetProcessType());
     *launch_result = LAUNCH_RESULT_SUCCESS;
 
-#if !defined(OS_OPENBSD)
     if (handle) {
       // This is just a starting score for a renderer or extension (the
       // only types of processes that will be started this way).  It will
@@ -95,13 +97,13 @@
       ZygoteHostImpl::GetInstance()->AdjustRendererOOMScore(
           handle, kLowestRendererOomScore);
     }
-#endif
 
     Process process;
     process.process = base::Process(handle);
     process.zygote = zygote_handle;
     return process;
   }
+#endif
 
   Process process;
   process.process = base::LaunchProcess(*command_line(), options);
@@ -119,10 +121,12 @@
     const ChildProcessLauncherHelper::Process& process,
     bool known_dead,
     int* exit_code) {
+#if !defined(OS_BSD)
   if (process.zygote) {
     return process.zygote->GetTerminationStatus(
         process.process.Handle(), known_dead, exit_code);
   }
+#endif
   if (known_dead) {
     return base::GetKnownDeadTerminationStatus(
         process.process.Handle(), exit_code);
@@ -144,13 +148,17 @@
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
   process.process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
+#if !defined(OS_BSD)
   if (process.zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
     process.zygote->EnsureProcessTerminated(process.process.Handle());
   } else {
+#endif
     base::EnsureProcessTerminated(std::move(process.process));
+#if !defined(OS_BSD)
   }
+#endif
 }
 
 void ChildProcessLauncherHelper::SetProcessPriorityOnLauncherThread(
