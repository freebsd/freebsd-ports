--- src/3rdparty/chromium/content/browser/child_process_launcher.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/content/browser/child_process_launcher.cc
@@ -198,7 +198,7 @@ void LaunchOnLauncherThread(const NotifyCallback& call
   // We need to close the client end of the IPC channel to reliably detect
   // child termination.
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (use_zygote) {
     base::ProcessHandle handle = ZygoteHostImpl::GetInstance()->ForkRequest(
         cmd_line->argv(), std::move(files_to_register), process_type);
@@ -296,7 +296,7 @@ void TerminateOnLauncherThread(bool zygote, base::Proc
   process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
@@ -398,7 +398,7 @@ void ChildProcessLauncher::Launch(
 
 void ChildProcessLauncher::UpdateTerminationStatus(bool known_dead) {
   DCHECK(CalledOnValidThread());
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (zygote_) {
     termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(process_.Handle(), known_dead, &exit_code_);
@@ -469,7 +469,7 @@ void ChildProcessLauncher::Notify(
   starting_ = false;
   process_ = std::move(process);
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   zygote_ = zygote;
 #endif
   if (process_.IsValid()) {
