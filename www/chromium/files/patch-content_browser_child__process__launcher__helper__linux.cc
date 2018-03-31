--- content/browser/child_process_launcher_helper_linux.cc.orig	2018-03-20 23:05:23.000000000 +0100
+++ content/browser/child_process_launcher_helper_linux.cc	2018-03-24 23:20:38.539917000 +0100
@@ -17,7 +17,9 @@
 #include "content/public/common/content_switches.h"
 #include "content/public/common/result_codes.h"
 #include "content/public/common/sandboxed_process_launcher_delegate.h"
+#if !defined(OS_BSD)
 #include "content/public/common/zygote_handle.h"
+#endif
 #include "gpu/config/gpu_switches.h"
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
 
@@ -70,6 +72,7 @@
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !defined(OS_BSD)
   ZygoteHandle zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? nullptr
@@ -101,6 +104,7 @@
     process.zygote = zygote_handle;
     return process;
   }
+#endif
 
   Process process;
   process.process = base::LaunchProcess(*command_line(), options);
@@ -118,10 +122,12 @@
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
@@ -140,13 +146,17 @@
     ChildProcessLauncherHelper::Process process) {
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
