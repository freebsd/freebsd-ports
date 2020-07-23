--- content/browser/renderer_host/render_message_filter.h.orig	2019-12-16 21:50:47 UTC
+++ content/browser/renderer_host/render_message_filter.h
@@ -87,14 +87,14 @@ class CONTENT_EXPORT RenderMessageFilter
                               mojo::PendingRemote<mojom::Widget> widget,
                               CreateFullscreenWidgetCallback callback) override;
   void HasGpuProcess(HasGpuProcessCallback callback) override;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(int32_t ns_tid,
                          base::ThreadPriority priority) override;
 #endif
 
   void OnResolveProxy(const GURL& url, IPC::Message* reply_msg);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriorityOnFileThread(base::PlatformThreadId ns_tid,
                                      base::ThreadPriority priority);
 #endif
