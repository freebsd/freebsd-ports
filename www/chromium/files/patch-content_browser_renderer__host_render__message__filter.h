--- content/browser/renderer_host/render_message_filter.h.orig	2017-04-19 19:06:33 UTC
+++ content/browser/renderer_host/render_message_filter.h
@@ -132,7 +132,7 @@ class CONTENT_EXPORT RenderMessageFilter
       const std::list<base::ProcessHandle>& handles);
   void OnResolveProxy(const GURL& url, IPC::Message* reply_msg);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriorityOnFileThread(base::PlatformThreadId ns_tid,
                                      base::ThreadPriority priority);
   void OnSetThreadPriority(base::PlatformThreadId ns_tid,
