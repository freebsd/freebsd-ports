--- content/browser/renderer_host/render_message_filter.h.orig	2022-08-31 12:19:35 UTC
+++ content/browser/renderer_host/render_message_filter.h
@@ -78,13 +78,13 @@ class RenderMessageFilter
   void GenerateRoutingID(GenerateRoutingIDCallback routing_id) override;
   void GenerateFrameRoutingID(GenerateFrameRoutingIDCallback callback) override;
   void HasGpuProcess(HasGpuProcessCallback callback) override;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void SetThreadType(int32_t ns_tid, base::ThreadType thread_type) override;
 #endif
 
   void OnResolveProxy(const GURL& url, IPC::Message* reply_msg);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void SetThreadTypeOnWorkerThread(base::PlatformThreadId ns_tid,
                                    base::ThreadType thread_type);
 #endif
