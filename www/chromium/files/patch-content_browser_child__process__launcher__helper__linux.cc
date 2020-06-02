--- content/browser/child_process_launcher_helper_linux.cc.orig	2020-05-13 18:39:42 UTC
+++ content/browser/child_process_launcher_helper_linux.cc
@@ -18,7 +18,9 @@
 #include "content/public/common/sandboxed_process_launcher_delegate.h"
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
 #include "services/service_manager/zygote/common/common_sandbox_support_linux.h"
+#if !defined(OS_BSD)
 #include "services/service_manager/zygote/common/zygote_handle.h"
+#endif
 #include "services/service_manager/zygote/host/zygote_communication_linux.h"
 #include "services/service_manager/zygote/host/zygote_host_impl_linux.h"
 
@@ -50,11 +52,13 @@ bool ChildProcessLauncherHelper::BeforeLaunchOnLaunche
   options->fds_to_remap = files_to_register.GetMappingWithIDAdjustment(
       base::GlobalDescriptors::kBaseDescriptor);
 
+#if !defined(OS_BSD)
   if (GetProcessType() == switches::kRendererProcess) {
     const int sandbox_fd = SandboxHostLinux::GetInstance()->GetChildSocket();
     options->fds_to_remap.push_back(
         std::make_pair(sandbox_fd, service_manager::GetSandboxFD()));
   }
+#endif
 
   options->environment = delegate_->GetEnvironment();
 
@@ -69,6 +73,7 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !defined(OS_BSD)
   service_manager::ZygoteHandle zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? nullptr
@@ -82,7 +87,6 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
         GetProcessType());
     *launch_result = LAUNCH_RESULT_SUCCESS;
 
-#if !defined(OS_OPENBSD)
     if (handle) {
       // It could be a renderer process or an utility process.
       int oom_score = content::kMiscOomScore;
@@ -92,13 +96,13 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
       service_manager::ZygoteHostImpl::GetInstance()->AdjustRendererOOMScore(
           handle, oom_score);
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
@@ -116,10 +120,14 @@ ChildProcessTerminationInfo ChildProcessLauncherHelper
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
@@ -143,13 +151,17 @@ void ChildProcessLauncherHelper::ForceNormalProcessTer
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
