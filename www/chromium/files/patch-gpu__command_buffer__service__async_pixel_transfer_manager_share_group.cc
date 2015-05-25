--- gpu/command_buffer/service/async_pixel_transfer_manager_share_group.cc.orig	2015-05-13 18:35:46.000000000 -0400
+++ gpu/command_buffer/service/async_pixel_transfer_manager_share_group.cc	2015-05-20 16:00:07.466335000 -0400
@@ -46,7 +46,7 @@
       : base::Thread(kAsyncTransferThreadName),
         initialized_(false) {
     Start();
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     SetPriority(base::ThreadPriority::BACKGROUND);
 #endif
   }
