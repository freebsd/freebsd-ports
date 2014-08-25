--- ./content/browser/child_process_launcher.cc.orig	2014-08-20 21:02:49.000000000 +0200
+++ ./content/browser/child_process_launcher.cc	2014-08-22 15:06:25.000000000 +0200
@@ -68,7 +68,7 @@
 #else
         terminate_child_on_shutdown_(true)
 #endif
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
         , zygote_(false)
 #endif
         {
@@ -234,7 +234,7 @@
     // child termination.
     base::ScopedFD ipcfd_closer(ipcfd);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     GetContentClient()->browser()->
         GetAdditionalMappedFilesForChildProcess(*cmd_line, child_process_id,
                                                 &files_to_register);
@@ -244,7 +244,7 @@
                                                           process_type);
     } else
     // Fall through to the normal posix case below when we're not zygoting.
-#endif  // !defined(OS_MACOSX)
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
     {
       // Convert FD mapping to FileHandleMappingVector
       base::FileHandleMappingVector fds_to_map;
@@ -255,7 +255,7 @@
                 base::GlobalDescriptors::kBaseDescriptor));
       }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       if (process_type == switches::kRendererProcess) {
         const int sandbox_fd =
             RenderSandboxHostLinux::GetInstance()->GetRendererSocket();
@@ -263,7 +263,7 @@
             sandbox_fd,
             GetSandboxFD()));
       }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && !defined(OS_BSD)
 
       // Actually launch the app.
       base::LaunchOptions options;
@@ -322,7 +322,7 @@
       base::Bind(
           &Context::Notify,
           this_object.get(),
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
           use_zygote,
 #endif
           handle));
@@ -330,7 +330,7 @@
   }
 
   void Notify(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -343,7 +343,7 @@
     if (!handle)
       LOG(ERROR) << "Failed to launch child process";
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     zygote_ = zygote;
 #endif
     if (client_) {
@@ -370,7 +370,7 @@
         BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
         base::Bind(
             &Context::TerminateInternal,
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
             zygote_,
 #endif
             process_.handle()));
@@ -387,7 +387,7 @@
   }
 
   static void TerminateInternal(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -401,13 +401,13 @@
     process.Terminate(RESULT_CODE_NORMAL_EXIT);
     // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     if (zygote) {
       // If the renderer was created via a zygote, we have to proxy the reaping
       // through the zygote process.
       ZygoteHostImpl::GetInstance()->EnsureProcessTerminated(handle);
     } else
-#endif  // !OS_MACOSX
+#endif  // !OS_MACOSX && !OS_BSD
     {
       base::EnsureProcessTerminated(handle);
     }
@@ -428,7 +428,7 @@
 #if defined(OS_ANDROID)
   // The fd to close after creating the process.
   int ipcfd_;
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   bool zygote_;
 #endif
 };
@@ -470,7 +470,7 @@
       *exit_code = context_->exit_code_;
     return context_->termination_status_;
   }
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (context_->zygote_) {
     context_->termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(handle, known_dead, &context_->exit_code_);
