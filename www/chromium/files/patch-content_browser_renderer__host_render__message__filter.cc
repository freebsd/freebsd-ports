--- content/browser/renderer_host/render_message_filter.cc.orig	2018-06-13 00:10:17.000000000 +0200
+++ content/browser/renderer_host/render_message_filter.cc	2018-07-19 11:46:53.426069000 +0200
@@ -76,7 +76,7 @@
 #if defined(OS_MACOSX)
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/threading/platform_thread.h"
 #endif
@@ -194,7 +194,7 @@
   std::move(callback).Run(route_id);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void RenderMessageFilter::SetThreadPriorityOnFileThread(
     base::PlatformThreadId ns_tid,
     base::ThreadPriority priority) {
@@ -215,7 +215,7 @@
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void RenderMessageFilter::SetThreadPriority(int32_t ns_tid,
                                             base::ThreadPriority priority) {
   constexpr base::TaskTraits kTraits = {
