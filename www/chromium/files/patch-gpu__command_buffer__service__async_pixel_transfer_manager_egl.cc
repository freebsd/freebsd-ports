--- gpu/command_buffer/service/async_pixel_transfer_manager_egl.cc.orig	2015-05-13 18:35:46.000000000 -0400
+++ gpu/command_buffer/service/async_pixel_transfer_manager_egl.cc	2015-05-20 15:58:33.229171000 -0400
@@ -89,7 +89,7 @@
  public:
   TransferThread() : base::Thread(kAsyncTransferThreadName) {
     Start();
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     SetPriority(base::ThreadPriority::BACKGROUND);
 #endif
   }
@@ -465,14 +465,14 @@
 
 void AsyncPixelTransferDelegateEGL::WaitForTransferCompletion() {
   if (state_->TransferIsInProgress()) {
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     g_transfer_thread.Pointer()->SetPriority(base::ThreadPriority::DISPLAY);
 #endif
 
     state_->WaitForTransferCompletion();
     DCHECK(!state_->TransferIsInProgress());
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     g_transfer_thread.Pointer()->SetPriority(base::ThreadPriority::BACKGROUND);
 #endif
   }
