--- content/browser/renderer_host/render_process_host_impl.h.orig	2020-03-03 18:53:54 UTC
+++ content/browser/renderer_host/render_process_host_impl.h
@@ -473,10 +473,10 @@ class CONTENT_EXPORT RenderProcessHostImpl
     is_for_guests_only_ = is_for_guests_only;
   }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   // Called when a video capture stream or an audio stream is added or removed
   // and used to determine if the process should be backgrounded or not.
