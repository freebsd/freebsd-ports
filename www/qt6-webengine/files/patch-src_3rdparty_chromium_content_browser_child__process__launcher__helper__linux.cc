--- src/3rdparty/chromium/content/browser/child_process_launcher_helper_linux.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/content/browser/child_process_launcher_helper_linux.cc
@@ -21,8 +21,12 @@
 #include "content/public/common/result_codes.h"
 #include "content/public/common/sandboxed_process_launcher_delegate.h"
 #include "content/public/common/zygote/sandbox_support_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "content/public/common/zygote/zygote_handle.h"
 #include "sandbox/policy/linux/sandbox_linux.h"
+#else
+#include "sandbox/policy/sandbox.h"
+#endif
 
 namespace content {
 namespace internal {
@@ -46,14 +50,20 @@ bool ChildProcessLauncherHelper::IsUsingLaunchOptions(
 }
 
 bool ChildProcessLauncherHelper::IsUsingLaunchOptions() {
+#if !BUILDFLAG(IS_BSD)
   return !GetZygoteForLaunch();
+#else
+  return true;
+#endif
 }
 
 bool ChildProcessLauncherHelper::BeforeLaunchOnLauncherThread(
     PosixFileDescriptorInfo& files_to_register,
     base::LaunchOptions* options) {
   if (options) {
+#if !BUILDFLAG(IS_BSD)
     DCHECK(!GetZygoteForLaunch());
+#endif
     // Convert FD mapping to FileHandleMappingVector
     options->fds_to_remap = files_to_register.GetMappingWithIDAdjustment(
         base::GlobalDescriptors::kBaseDescriptor);
@@ -65,7 +75,9 @@ bool ChildProcessLauncherHelper::BeforeLaunchOnLaunche
 
     options->environment = delegate_->GetEnvironment();
   } else {
+#if !BUILDFLAG(IS_BSD)
     DCHECK(GetZygoteForLaunch());
+#endif
     // Environment variables could be supported in the future, but are not
     // currently supported when launching with the zygote.
     DCHECK(delegate_->GetEnvironment().empty());
@@ -82,6 +94,7 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
     int* launch_result) {
   *is_synchronous_launch = true;
   Process process;
+#if !BUILDFLAG(IS_BSD)
   ZygoteCommunication* zygote_handle = GetZygoteForLaunch();
   if (zygote_handle) {
     // TODO(crbug.com/569191): If chrome supported multiple zygotes they could
@@ -92,7 +105,6 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
         GetProcessType());
     *launch_result = LAUNCH_RESULT_SUCCESS;
 
-#if !BUILDFLAG(IS_OPENBSD)
     if (handle) {
       // It could be a renderer process or an utility process.
       int oom_score = content::kMiscOomScore;
@@ -101,15 +113,17 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
         oom_score = content::kLowestRendererOomScore;
       ZygoteHostImpl::GetInstance()->AdjustRendererOOMScore(handle, oom_score);
     }
-#endif
 
     process.process = base::Process(handle);
     process.zygote = zygote_handle;
   } else {
+#endif
     process.process = base::LaunchProcess(*command_line(), *options);
     *launch_result = process.process.IsValid() ? LAUNCH_RESULT_SUCCESS
                                                : LAUNCH_RESULT_FAILURE;
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS)
   if (GetProcessType() == switches::kRendererProcess) {
@@ -131,10 +145,14 @@ ChildProcessTerminationInfo ChildProcessLauncherHelper
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
@@ -160,13 +178,17 @@ void ChildProcessLauncherHelper::ForceNormalProcessTer
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
@@ -178,11 +200,13 @@ void ChildProcessLauncherHelper::SetProcessPriorityOnL
   }
 }
 
+#if !BUILDFLAG(IS_BSD)
 ZygoteCommunication* ChildProcessLauncherHelper::GetZygoteForLaunch() {
   return base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
              ? nullptr
              : delegate_->GetZygote();
 }
+#endif
 
 base::File OpenFileToShare(const base::FilePath& path,
                            base::MemoryMappedFile::Region* region) {
