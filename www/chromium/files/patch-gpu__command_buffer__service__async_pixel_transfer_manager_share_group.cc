--- gpu/command_buffer/service/async_pixel_transfer_manager_share_group.cc.orig	2015-09-01 16:10:43.000000000 -0400
+++ gpu/command_buffer/service/async_pixel_transfer_manager_share_group.cc	2015-09-03 10:44:42.860094000 -0400
@@ -48,7 +48,7 @@
       : base::Thread(kAsyncTransferThreadName),
         initialized_(false) {
     base::Thread::Options options;
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     options.priority = base::ThreadPriority::BACKGROUND;
 #endif
     StartWithOptions(options);
