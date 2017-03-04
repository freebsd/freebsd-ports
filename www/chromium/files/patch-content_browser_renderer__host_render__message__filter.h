--- content/browser/renderer_host/render_message_filter.h.orig	2017-02-02 02:02:53 UTC
+++ content/browser/renderer_host/render_message_filter.h
@@ -175,7 +175,7 @@ class CONTENT_EXPORT RenderMessageFilter
   void OnDeletedDiscardableSharedMemory(
       discardable_memory::DiscardableSharedMemoryId id);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriorityOnFileThread(base::PlatformThreadId ns_tid,
                                      base::ThreadPriority priority);
   void OnSetThreadPriority(base::PlatformThreadId ns_tid,
