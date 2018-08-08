--- content/browser/child_process_launcher_helper_linux.cc.orig	2018-08-01 00:08:43.000000000 +0200
+++ content/browser/child_process_launcher_helper_linux.cc	2018-08-04 18:57:46.407465000 +0200
@@ -18,7 +18,9 @@
 #include "gpu/config/gpu_switches.h"
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
 #include "services/service_manager/zygote/common/common_sandbox_support_linux.h"
+#if !defined(OS_BSD)
 #include "services/service_manager/zygote/common/zygote_handle.h"
+#endif
 #include "services/service_manager/zygote/host/zygote_communication_linux.h"
 #include "services/service_manager/zygote/host/zygote_host_impl_linux.h"
 
@@ -72,6 +74,7 @@
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !defined(OS_BSD)
   service_manager::ZygoteHandle zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? nullptr
@@ -85,7 +88,6 @@
         GetProcessType());
     *launch_result = LAUNCH_RESULT_SUCCESS;
 
-#if !defined(OS_OPENBSD)
     if (handle) {
       // This is just a starting score for a renderer or extension (the
       // only types of processes that will be started this way).  It will
@@ -96,13 +98,13 @@
       service_manager::ZygoteHostImpl::GetInstance()->AdjustRendererOOMScore(
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
@@ -120,10 +122,14 @@
     const ChildProcessLauncherHelper::Process& process,
     bool known_dead) {
   ChildProcessTerminationInfo info;
+#if !defined(OS_BSD)
   if (process.zygote) {
     info.status = process.zygote->GetTerminationStatus(
         process.process.Handle(), known_dead, &info.exit_code);
   } else if (known_dead) {
+#else
+  if (known_dead) {
+#endif
     info.status = base::GetKnownDeadTerminationStatus(process.process.Handle(),
                                                       &info.exit_code);
   } else {
@@ -147,13 +153,17 @@
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
   process.process.Terminate(service_manager::RESULT_CODE_NORMAL_EXIT, false);
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
