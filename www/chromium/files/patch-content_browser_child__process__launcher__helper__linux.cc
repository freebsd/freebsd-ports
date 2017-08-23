--- content/browser/child_process_launcher_helper_linux.cc.orig	2017-07-25 21:04:55.000000000 +0200
+++ content/browser/child_process_launcher_helper_linux.cc	2017-08-02 00:41:59.942814000 +0200
@@ -66,6 +66,7 @@
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !defined(OS_BSD)
   ZygoteHandle zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? nullptr
@@ -82,6 +83,7 @@
     process.zygote = zygote_handle;
     return process;
   }
+#endif
 
   Process process;
   process.process = base::LaunchProcess(*command_line(), options);
@@ -100,10 +102,12 @@
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
@@ -122,13 +126,17 @@
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
 
 void ChildProcessLauncherHelper::SetProcessPriorityOnLauncherThread(
