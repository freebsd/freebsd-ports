--- content/browser/child_process_launcher_helper_linux.cc.orig	2022-06-17 14:20:10 UTC
+++ content/browser/child_process_launcher_helper_linux.cc
@@ -20,7 +20,9 @@
 #include "content/public/common/result_codes.h"
 #include "content/public/common/sandboxed_process_launcher_delegate.h"
 #include "content/public/common/zygote/sandbox_support_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "content/public/common/zygote/zygote_handle.h"
+#endif
 #include "sandbox/policy/linux/sandbox_linux.h"
 
 namespace content {
@@ -74,6 +76,7 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !BUILDFLAG(IS_BSD)
   ZygoteHandle zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? nullptr
@@ -87,7 +90,6 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
         GetProcessType());
     *launch_result = LAUNCH_RESULT_SUCCESS;
 
-#if !BUILDFLAG(IS_OPENBSD)
     if (handle) {
       // It could be a renderer process or an utility process.
       int oom_score = content::kMiscOomScore;
@@ -96,13 +98,13 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
         oom_score = content::kLowestRendererOomScore;
       ZygoteHostImpl::GetInstance()->AdjustRendererOOMScore(handle, oom_score);
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
@@ -120,10 +122,14 @@ ChildProcessTerminationInfo ChildProcessLauncherHelper
     const ChildProcessLauncherHelper::Process& process,
     bool known_dead) {
   ChildProcessTerminationInfo info;
+#if !BUILDFLAG(IS_BSD)
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
@@ -147,13 +153,17 @@ void ChildProcessLauncherHelper::ForceNormalProcessTer
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
   process.process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
+#if !BUILDFLAG(IS_BSD)
   if (process.zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
     process.zygote->EnsureProcessTerminated(process.process.Handle());
   } else {
+#endif
     base::EnsureProcessTerminated(std::move(process.process));
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 }
 
 void ChildProcessLauncherHelper::SetProcessPriorityOnLauncherThread(
