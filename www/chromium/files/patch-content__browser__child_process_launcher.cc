--- ./content/browser/child_process_launcher.cc.orig	2010-12-16 02:11:58.000000000 +0100
+++ ./content/browser/child_process_launcher.cc	2010-12-20 20:15:08.000000000 +0100
@@ -20,7 +20,7 @@
 #if defined(OS_WIN)
 #include "base/file_path.h"
 #include "chrome/common/sandbox_policy.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "base/singleton.h"
 #include "chrome/browser/crash_handler_host_linux.h"
 #include "chrome/browser/zygote_host_linux.h"
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
     if (use_zygote) {
       base::GlobalDescriptors::Mapping mapping;
       mapping.push_back(std::pair<uint32_t, int>(kPrimaryIPCChannel, ipcfd));
@@ -131,7 +131,7 @@
           ipcfd,
           kPrimaryIPCChannel + base::GlobalDescriptors::kBaseDescriptor));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       // On Linux, we need to add some extra file descriptors for crash handling
       // and the sandbox.
       bool is_renderer =
@@ -163,7 +163,7 @@
             sandbox_fd,
             kSandboxIPCChannel + base::GlobalDescriptors::kBaseDescriptor));
       }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
       bool launched = false;
 #if defined(OS_MACOSX)
@@ -199,20 +199,20 @@
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
@@ -232,7 +232,7 @@
         BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
         NewRunnableFunction(
             &ChildProcessLauncher::Context::TerminateInternal,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
             zygote_,
 #endif
             process_.handle()));
@@ -240,7 +240,7 @@
   }
 
   static void TerminateInternal(
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -250,13 +250,13 @@
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
@@ -269,7 +269,7 @@
   base::Process process_;
   bool starting_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   bool zygote_;
 #endif
 };
@@ -315,7 +315,7 @@
     int* exit_code) {
   base::TerminationStatus status;
   base::ProcessHandle handle = context_->process_.handle();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   if (context_->zygote_) {
     status = ZygoteHost::GetInstance()->GetTerminationStatus(handle, exit_code);
   } else
