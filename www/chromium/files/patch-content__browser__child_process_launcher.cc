--- content/browser/child_process_launcher.cc.orig	2016-03-04 22:27:56.807672733 +0100
+++ content/browser/child_process_launcher.cc	2016-03-04 22:34:35.624645928 +0100
@@ -116,7 +116,11 @@
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
@@ -145,7 +149,7 @@
 #endif
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   std::map<int, base::MemoryMappedFile::Region> regions;
   GetContentClient()->browser()->GetAdditionalMappedFilesForChildProcess(
       *cmd_line, child_process_id, files_to_register.get()
@@ -178,7 +182,7 @@
     }
   }
 #endif  // defined(V8_USE_EXTERNAL_STARTUP_DATA)
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_ANDROID)
   files_to_register->Share(
@@ -198,21 +202,21 @@
   // We need to close the client end of the IPC channel to reliably detect
   // child termination.
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (use_zygote) {
     base::ProcessHandle handle = ZygoteHostImpl::GetInstance()->ForkRequest(
         cmd_line->argv(), std::move(files_to_register), process_type);
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
@@ -220,7 +224,7 @@
           sandbox_fd,
           GetSandboxFD()));
     }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && !defined(OS_BSD)
 
     // Actually launch the app.
     base::LaunchOptions options;
@@ -296,13 +300,13 @@
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
+#endif  // !OS_MACOSX && !defined(OS_BSD)
     base::EnsureProcessTerminated(std::move(process));
 #endif  // OS_POSIX
 #endif  // defined(OS_ANDROID)
@@ -398,7 +402,7 @@
 
 void ChildProcessLauncher::UpdateTerminationStatus(bool known_dead) {
   DCHECK(CalledOnValidThread());
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (zygote_) {
     termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(process_.Handle(), known_dead, &exit_code_);
@@ -406,7 +410,7 @@
     termination_status_ =
         base::GetKnownDeadTerminationStatus(process_.Handle(), &exit_code_);
   } else {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   if (known_dead) {
     termination_status_ =
         base::GetKnownDeadTerminationStatus(process_.Handle(), &exit_code_);
@@ -469,7 +473,7 @@
   starting_ = false;
   process_ = std::move(process);
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   zygote_ = zygote;
 #endif
   if (process_.IsValid()) {
