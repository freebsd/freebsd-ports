--- content/browser/child_process_launcher_helper_linux.cc.orig	2017-04-19 19:06:33 UTC
+++ content/browser/child_process_launcher_helper_linux.cc
@@ -67,6 +67,7 @@ ChildProcessLauncherHelper::LaunchProces
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !defined(OS_BSD)
   ZygoteHandle* zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote) ?
       nullptr : delegate_->GetZygote();
@@ -86,6 +87,7 @@ ChildProcessLauncherHelper::LaunchProces
     process.zygote = *zygote_handle;
     return process;
   }
+#endif
 
   Process process;
   process.process = base::LaunchProcess(*command_line(), options);
@@ -105,10 +107,12 @@ base::TerminationStatus ChildProcessLaun
     const ChildProcessLauncherHelper::Process& process,
     bool known_dead,
     int* exit_code) {
+#if !defined(OS_BSD)
   if (process.zygote) {
     return process.zygote->GetTerminationStatus(
         process.process.Handle(), known_dead, exit_code);
   }
+#endif
   if (known_dead) {
     return base::GetKnownDeadTerminationStatus(
         process.process.Handle(), exit_code);
@@ -127,13 +131,17 @@ void ChildProcessLauncherHelper::ForceNo
     ChildProcessLauncherHelper::Process process) {
   process.process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
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
 
 // static
