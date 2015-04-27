--- content/browser/child_process_launcher.cc.orig	2015-04-19 00:30:35.000000000 +0200
+++ content/browser/child_process_launcher.cc	2015-04-19 00:43:33.000000000 +0200
@@ -120,7 +120,7 @@
   // Notifies the client about the result of the operation.
   // Runs on the UI thread.
   void Notify(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::Process process);
@@ -131,7 +131,7 @@
                                              bool background);
 
   static void TerminateInternal(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::Process process);
@@ -144,7 +144,7 @@
 #if defined(OS_ANDROID)
   // The fd to close after creating the process.
   base::ScopedFD ipcfd_;
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   bool zygote_;
 #endif
   bool starting_;
@@ -158,7 +158,7 @@
       client_thread_id_(BrowserThread::UI),
       termination_status_(base::TERMINATION_STATUS_NORMAL_TERMINATION),
       exit_code_(RESULT_CODE_NORMAL_EXIT),
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       zygote_(false),
 #endif
       starting_(true),
@@ -238,7 +238,7 @@
 }
 
 void ChildProcessLauncher::Context::UpdateTerminationStatus(bool known_dead) {
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (zygote_) {
     termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(process_.Handle(), known_dead, &exit_code_);
@@ -312,7 +312,7 @@
   bool launch_elevated = delegate->ShouldLaunchElevated();
 #elif defined(OS_ANDROID)
   // Uses |ipcfd_| instead of |ipcfd| on Android.
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   base::EnvironmentMap env = delegate->GetEnvironment();
   base::ScopedFD ipcfd = delegate->TakeIpcFd();
 #elif defined(OS_POSIX)
@@ -366,7 +366,7 @@
   // We need to close the client end of the IPC channel to reliably detect
   // child termination.
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   GetContentClient()->browser()->GetAdditionalMappedFilesForChildProcess(
       *cmd_line, child_process_id, files_to_register.get());
   if (use_zygote) {
@@ -375,14 +375,14 @@
     process = base::Process(handle);
   } else
   // Fall through to the normal posix case below when we're not zygoting.
-#endif  // !defined(OS_MACOSX)
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
   {
     // Convert FD mapping to FileHandleMappingVector
     base::FileHandleMappingVector fds_to_map =
         files_to_register->GetMappingWithIDAdjustment(
             base::GlobalDescriptors::kBaseDescriptor);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     if (process_type == switches::kRendererProcess) {
       const int sandbox_fd =
           RenderSandboxHostLinux::GetInstance()->GetRendererSocket();
@@ -390,7 +390,7 @@
           sandbox_fd,
           GetSandboxFD()));
     }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && !defined(OS_BSD)
 
     // Actually launch the app.
     base::LaunchOptions options;
@@ -446,7 +446,7 @@
       client_thread_id, FROM_HERE,
       base::Bind(&Context::Notify,
                  this_object.get(),
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
                  use_zygote,
 #endif
                  base::Passed(&process)));
@@ -454,7 +454,7 @@
 }
 
 void ChildProcessLauncher::Context::Notify(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     bool zygote,
 #endif
     base::Process process) {
@@ -467,7 +467,7 @@
   if (!process_.IsValid())
     LOG(ERROR) << "Failed to launch child process";
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   zygote_ = zygote;
 #endif
   if (client_) {
@@ -493,7 +493,7 @@
   BrowserThread::PostTask(
       BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
       base::Bind(&Context::TerminateInternal,
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
                 zygote_,
 #endif
                 base::Passed(&process_)));
@@ -511,7 +511,7 @@
 
 // static
 void ChildProcessLauncher::Context::TerminateInternal(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     bool zygote,
 #endif
     base::Process process) {
@@ -525,13 +525,13 @@
   process.Terminate(RESULT_CODE_NORMAL_EXIT);
   // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
     ZygoteHostImpl::GetInstance()->EnsureProcessTerminated(process.Handle());
   } else
-#endif  // !OS_MACOSX
+#endif  // !OS_MACOSX && !OS_BSD
   base::EnsureProcessTerminated(process.Pass());
 #endif  // OS_POSIX
 #endif  // defined(OS_ANDROID)
