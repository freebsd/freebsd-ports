--- content/browser/renderer_host/render_message_filter.h.orig	2018-06-13 00:10:17.000000000 +0200
+++ content/browser/renderer_host/render_message_filter.h	2018-07-20 17:25:54.254096000 +0200
@@ -114,14 +114,14 @@
       const url::Origin& cache_storage_origin,
       const std::string& cache_storage_cache_name) override;
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
