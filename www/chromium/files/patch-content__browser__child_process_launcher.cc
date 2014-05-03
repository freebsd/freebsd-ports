--- ./content/browser/child_process_launcher.cc.orig	2014-04-24 22:35:48.000000000 +0200
+++ ./content/browser/child_process_launcher.cc	2014-04-24 23:23:44.000000000 +0200
@@ -58,7 +58,7 @@
         termination_status_(base::TERMINATION_STATUS_NORMAL_TERMINATION),
         exit_code_(RESULT_CODE_NORMAL_EXIT),
         starting_(true)
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
         , zygote_(false)
 #endif
         {
@@ -245,7 +245,7 @@
     // child termination.
     file_util::ScopedFD ipcfd_closer(&ipcfd);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     GetContentClient()->browser()->
         GetAdditionalMappedFilesForChildProcess(*cmd_line, child_process_id,
                                                 &files_to_register);
@@ -266,7 +266,7 @@
                 base::GlobalDescriptors::kBaseDescriptor));
       }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       if (process_type == switches::kRendererProcess) {
         const int sandbox_fd =
             RenderSandboxHostLinux::GetInstance()->GetRendererSocket();
@@ -320,7 +320,7 @@
       base::Bind(
           &Context::Notify,
           this_object.get(),
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
           use_zygote,
 #endif
           handle));
@@ -328,7 +328,7 @@
   }
 
   void Notify(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -341,7 +341,7 @@
     if (!handle)
       LOG(ERROR) << "Failed to launch child process";
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     zygote_ = zygote;
 #endif
     if (client_) {
@@ -368,7 +368,7 @@
         BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
         base::Bind(
             &Context::TerminateInternal,
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
             zygote_,
 #endif
             process_.handle()));
@@ -382,7 +382,7 @@
   }
 
   static void TerminateInternal(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -396,7 +396,7 @@
     process.Terminate(RESULT_CODE_NORMAL_EXIT);
     // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     if (zygote) {
       // If the renderer was created via a zygote, we have to proxy the reaping
       // through the zygote process.
@@ -423,7 +423,7 @@
 #if defined(OS_ANDROID)
   // The fd to close after creating the process.
   int ipcfd_;
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   bool zygote_;
 #endif
 };
@@ -481,7 +481,7 @@
       *exit_code = context_->exit_code_;
     return context_->termination_status_;
   }
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (context_->zygote_) {
     context_->termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(handle, known_dead, &context_->exit_code_);
