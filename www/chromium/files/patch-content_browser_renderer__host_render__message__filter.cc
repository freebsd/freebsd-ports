--- content/browser/renderer_host/render_message_filter.cc.orig	2021-04-14 18:41:02 UTC
+++ content/browser/renderer_host/render_message_filter.cc
@@ -70,7 +70,7 @@
 #if defined(OS_MAC)
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/threading/platform_thread.h"
 #endif
@@ -127,7 +127,7 @@ void RenderMessageFilter::GenerateFrameRoutingID(
   std::move(callback).Run(routing_id, frame_token, devtools_frame_token);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void RenderMessageFilter::SetThreadPriorityOnFileThread(
     base::PlatformThreadId ns_tid,
     base::ThreadPriority priority) {
@@ -148,7 +148,7 @@ void RenderMessageFilter::SetThreadPriorityOnFileThrea
 }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void RenderMessageFilter::SetThreadPriority(int32_t ns_tid,
                                             base::ThreadPriority priority) {
   constexpr base::TaskTraits kTraits = {
