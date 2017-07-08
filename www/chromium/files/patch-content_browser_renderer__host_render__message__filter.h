--- content/browser/renderer_host/render_message_filter.h.orig	2017-06-05 19:03:07 UTC
+++ content/browser/renderer_host/render_message_filter.h
@@ -130,7 +130,7 @@ class CONTENT_EXPORT RenderMessageFilter
                                 bool has_gpu);
   void OnResolveProxy(const GURL& url, IPC::Message* reply_msg);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriorityOnFileThread(base::PlatformThreadId ns_tid,
                                      base::ThreadPriority priority);
   void OnSetThreadPriority(base::PlatformThreadId ns_tid,
