--- content/browser/child_process_launcher.cc.orig	2011-05-06 12:02:54.000000000 +0300
+++ content/browser/child_process_launcher.cc	2011-06-04 15:13:25.939378747 +0300
@@ -20,7 +20,7 @@
 #if defined(OS_WIN)
 #include "base/file_path.h"
 #include "chrome/common/sandbox_policy.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "base/memory/singleton.h"
 #include "chrome/browser/crash_handler_host_linux.h"
 #include "content/browser/zygote_host_linux.h"
@@ -45,7 +45,7 @@
       : client_(NULL),
         client_thread_id_(BrowserThread::UI),
         starting_(true)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
         , zygote_(false)
 #endif
         {
@@ -110,7 +110,7 @@
     handle = sandbox::StartProcessWithAccess(cmd_line, exposed_dir);
 #elif defined(OS_POSIX)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     // On Linux, we need to add some extra file descriptors for crash handling.
     std::string process_type =
         cmd_line->GetSwitchValueASCII(switches::kProcessType);
@@ -151,7 +151,7 @@
           ipcfd,
           kPrimaryIPCChannel + base::GlobalDescriptors::kBaseDescriptor));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       if (crash_signal_fd >= 0) {
         fds_to_map.push_back(std::make_pair(
             crash_signal_fd,
@@ -164,7 +164,7 @@
             sandbox_fd,
             kSandboxIPCChannel + base::GlobalDescriptors::kBaseDescriptor));
       }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
       bool launched = false;
 #if defined(OS_MACOSX)
@@ -200,20 +200,20 @@
         NewRunnableMethod(
             this,
             &ChildProcessLauncher::Context::Notify,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
             use_zygote,
 #endif
             handle));
   }
 
   void Notify(
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
     starting_ = false;
     process_.set_handle(handle);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     zygote_ = zygote;
 #endif
     if (client_) {
@@ -233,7 +233,7 @@
         BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
         NewRunnableFunction(
             &ChildProcessLauncher::Context::TerminateInternal,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
             zygote_,
 #endif
             process_.handle()));
@@ -246,7 +246,7 @@
   }
 
   static void TerminateInternal(
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -256,13 +256,13 @@
     process.Terminate(ResultCodes::NORMAL_EXIT);
     // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     if (zygote) {
       // If the renderer was created via a zygote, we have to proxy the reaping
       // through the zygote process.
       ZygoteHost::GetInstance()->EnsureProcessTerminated(handle);
     } else
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
     {
       ProcessWatcher::EnsureProcessTerminated(handle);
     }
@@ -275,7 +275,7 @@
   base::Process process_;
   bool starting_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   bool zygote_;
 #endif
 };
@@ -321,7 +321,7 @@
     int* exit_code) {
   base::TerminationStatus status;
   base::ProcessHandle handle = context_->process_.handle();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   if (context_->zygote_) {
     status = ZygoteHost::GetInstance()->GetTerminationStatus(handle, exit_code);
   } else
