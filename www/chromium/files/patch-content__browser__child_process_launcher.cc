--- content/browser/child_process_launcher.cc.orig	2015-01-21 20:28:16 UTC
+++ content/browser/child_process_launcher.cc
@@ -69,7 +69,7 @@
 #else
         terminate_child_on_shutdown_(true)
 #endif
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
         , zygote_(false)
 #endif
         {
@@ -190,7 +190,7 @@
     bool launch_elevated = delegate->ShouldLaunchElevated();
 #elif defined(OS_ANDROID)
     // Uses |ipcfd_| instead of |ipcfd| on Android.
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
     base::EnvironmentMap env = delegate->GetEnvironment();
     base::ScopedFD ipcfd = delegate->TakeIpcFd();
 #elif defined(OS_POSIX)
@@ -253,7 +253,7 @@
     // We need to close the client end of the IPC channel to reliably detect
     // child termination.
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     GetContentClient()->browser()->GetAdditionalMappedFilesForChildProcess(
         *cmd_line, child_process_id, files_to_register.get());
     if (use_zygote) {
@@ -261,14 +261,14 @@
           cmd_line->argv(), files_to_register.Pass(), process_type);
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
@@ -276,7 +276,7 @@
             sandbox_fd,
             GetSandboxFD()));
       }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && !defined(OS_BSD)
 
       // Actually launch the app.
       base::LaunchOptions options;
@@ -335,7 +335,7 @@
       base::Bind(
           &Context::Notify,
           this_object.get(),
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
           use_zygote,
 #endif
           base::Passed(base::Process(handle))));
@@ -343,7 +343,7 @@
   }
 
   void Notify(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::Process process) {
@@ -356,7 +356,7 @@
     if (!process_.IsValid())
       LOG(ERROR) << "Failed to launch child process";
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     zygote_ = zygote;
 #endif
     if (client_) {
@@ -383,7 +383,7 @@
         BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
         base::Bind(
             &Context::TerminateInternal,
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
             zygote_,
 #endif
             base::Passed(&process_)));
@@ -398,7 +398,7 @@
   }
 
   static void TerminateInternal(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::Process process) {
@@ -412,13 +412,13 @@
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
     {
       base::EnsureProcessTerminated(process.Handle());
     }
@@ -438,7 +438,7 @@
 #if defined(OS_ANDROID)
   // The fd to close after creating the process.
   base::ScopedFD ipcfd_;
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   bool zygote_;
 #endif
 };
@@ -479,7 +479,7 @@
       *exit_code = context_->exit_code_;
     return context_->termination_status_;
   }
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (context_->zygote_) {
     context_->termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(context_->process_.Handle(), known_dead,
