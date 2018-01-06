--- src/3rdparty/chromium/content/browser/child_process_launcher.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/browser/child_process_launcher.cc
@@ -249,7 +249,7 @@ void LaunchOnLauncherThread(const Notify
   // We need to close the client end of the IPC channel to reliably detect
   // child termination.
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   ZygoteHandle* zygote_handle =
       !base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? delegate->GetZygote()
@@ -267,7 +267,7 @@ void LaunchOnLauncherThread(const Notify
     process = base::Process(handle);
   } else
   // Fall through to the normal posix case below when we're not zygoting.
-#endif  // !defined(OS_MACOSX)
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
   {
     // Convert FD mapping to FileHandleMappingVector
     base::FileHandleMappingVector fds_to_map =
@@ -358,7 +358,7 @@ void TerminateOnLauncherThread(ZygoteHan
   process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
@@ -475,7 +475,7 @@ void ChildProcessLauncher::Launch(Sandbo
 
 void ChildProcessLauncher::UpdateTerminationStatus(bool known_dead) {
   DCHECK(CalledOnValidThread());
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (zygote_) {
     termination_status_ = zygote_->GetTerminationStatus(
         process_.Handle(), known_dead, &exit_code_);
@@ -549,7 +549,7 @@ void ChildProcessLauncher::Notify(Zygote
                                     mojo_child_token_, process_error_callback_);
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   zygote_ = zygote;
 #endif
   if (process_.IsValid()) {
