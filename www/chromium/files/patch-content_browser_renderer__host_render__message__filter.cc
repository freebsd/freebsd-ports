--- content/browser/renderer_host/render_message_filter.cc.orig	2022-02-28 16:54:41 UTC
+++ content/browser/renderer_host/render_message_filter.cc
@@ -67,7 +67,7 @@
 #if BUILDFLAG(IS_MAC)
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #include "base/threading/platform_thread.h"
 #endif
@@ -129,7 +129,7 @@ void RenderMessageFilter::GenerateFrameRoutingID(
   std::move(callback).Run(routing_id, frame_token, devtools_frame_token);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void RenderMessageFilter::SetThreadPriorityOnFileThread(
     base::PlatformThreadId ns_tid,
     base::ThreadPriority priority) {
@@ -150,7 +150,7 @@ void RenderMessageFilter::SetThreadPriorityOnFileThrea
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void RenderMessageFilter::SetThreadPriority(int32_t ns_tid,
                                             base::ThreadPriority priority) {
   constexpr base::TaskTraits kTraits = {
