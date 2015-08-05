--- content/browser/child_process_launcher.cc.orig	2015-05-13 18:23:06.000000000 -0400
+++ content/browser/child_process_launcher.cc	2015-05-20 11:55:38.781168000 -0400
@@ -111,7 +111,11 @@
   base::EnvironmentMap env = delegate->GetEnvironment();
   base::ScopedFD ipcfd = delegate->TakeIpcFd();
 #elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#if !defined(OS_BSD)
   bool use_zygote = delegate->ShouldUseZygote();
+#else
+  bool use_zygote = false;
+#endif
   base::EnvironmentMap env = delegate->GetEnvironment();
   base::ScopedFD ipcfd = delegate->TakeIpcFd();
 #endif
@@ -157,7 +161,7 @@
   // We need to close the client end of the IPC channel to reliably detect
   // child termination.
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   GetContentClient()->browser()->GetAdditionalMappedFilesForChildProcess(
       *cmd_line, child_process_id, files_to_register.get());
   if (use_zygote) {
@@ -166,14 +170,14 @@
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
@@ -181,7 +185,7 @@
           sandbox_fd,
           GetSandboxFD()));
     }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && !defined(OS_BSD)
 
     // Actually launch the app.
     base::LaunchOptions options;
@@ -254,13 +258,13 @@
   process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
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
@@ -351,7 +355,7 @@
 
 void ChildProcessLauncher::UpdateTerminationStatus(bool known_dead) {
   DCHECK(CalledOnValidThread());
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (zygote_) {
     termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(process_.Handle(), known_dead, &exit_code_);
@@ -359,7 +363,7 @@
     termination_status_ =
         base::GetKnownDeadTerminationStatus(process_.Handle(), &exit_code_);
   } else {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   if (known_dead) {
     termination_status_ =
         base::GetKnownDeadTerminationStatus(process_.Handle(), &exit_code_);
@@ -433,7 +437,7 @@
   starting_ = false;
   process_ = process.Pass();
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   zygote_ = zygote;
 #endif
   if (process_.IsValid()) {
