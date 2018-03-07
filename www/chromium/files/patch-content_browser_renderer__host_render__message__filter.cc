--- content/browser/renderer_host/render_message_filter.cc.orig	2018-02-24 16:25:14.000000000 +0100
+++ content/browser/renderer_host/render_message_filter.cc	2018-03-04 01:08:51.920706000 +0100
@@ -80,7 +80,7 @@
 #include "content/common/mac/font_loader.h"
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/threading/platform_thread.h"
 #endif
@@ -211,7 +211,7 @@
 #endif  // defined(OS_MACOSX)
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void RenderMessageFilter::SetThreadPriorityOnFileThread(
     base::PlatformThreadId ns_tid,
     base::ThreadPriority priority) {
@@ -234,7 +234,7 @@
 
 void RenderMessageFilter::SetThreadPriority(int32_t ns_tid,
                                             base::ThreadPriority priority) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   constexpr base::TaskTraits kTraits = {
       base::MayBlock(), base::TaskPriority::USER_BLOCKING,
       base::TaskShutdownBehavior::CONTINUE_ON_SHUTDOWN};
