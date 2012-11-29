--- content/browser/child_process_launcher.cc.orig	2012-10-31 21:01:35.000000000 +0200
+++ content/browser/child_process_launcher.cc	2012-11-19 22:35:00.000000000 +0200
@@ -52,7 +52,7 @@
         termination_status_(base::TERMINATION_STATUS_NORMAL_TERMINATION),
         exit_code_(content::RESULT_CODE_NORMAL_EXIT),
         starting_(true)
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
         , zygote_(false)
 #endif
         {
@@ -188,7 +188,7 @@
     base::GlobalDescriptors::Mapping files_to_register;
     files_to_register.push_back(std::pair<base::GlobalDescriptors::Key, int>(
         kPrimaryIPCChannel, ipcfd));
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     content::GetContentClient()->browser()->
         GetAdditionalMappedFilesForChildProcess(*cmd_line, &files_to_register);
     if (use_zygote) {
@@ -209,7 +209,7 @@
             id_file.first + base::GlobalDescriptors::kBaseDescriptor));
       }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       if (process_type == switches::kRendererProcess) {
         const int sandbox_fd =
             RenderSandboxHostLinux::GetInstance()->GetRendererSocket();
@@ -261,7 +261,7 @@
       base::Bind(
           &Context::Notify,
           this_object.get(),
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
           use_zygote,
 #endif
           handle));
@@ -269,7 +269,7 @@
   }
 
   void Notify(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -282,7 +282,7 @@
     if (!handle)
       LOG(ERROR) << "Failed to launch child process";
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     zygote_ = zygote;
 #endif
     if (client_) {
@@ -305,7 +305,7 @@
         BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
         base::Bind(
             &Context::TerminateInternal,
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
             zygote_,
 #endif
             process_.handle()));
@@ -319,7 +319,7 @@
   }
 
   static void TerminateInternal(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -333,7 +333,7 @@
     process.Terminate(content::RESULT_CODE_NORMAL_EXIT);
     // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     if (zygote) {
       // If the renderer was created via a zygote, we have to proxy the reaping
       // through the zygote process.
@@ -360,7 +360,7 @@
 #if defined(OS_ANDROID)
   // The fd to close after creating the process.
   int ipcfd_;
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   bool zygote_;
 #endif
 };
@@ -413,7 +413,7 @@
       *exit_code = context_->exit_code_;
     return context_->termination_status_;
   }
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (context_->zygote_) {
     context_->termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(handle, &context_->exit_code_);
