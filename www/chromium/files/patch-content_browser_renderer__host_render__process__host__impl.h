--- content/browser/renderer_host/render_process_host_impl.h.orig	2022-02-07 13:39:41 UTC
+++ content/browser/renderer_host/render_process_host_impl.h
@@ -461,7 +461,7 @@ class CONTENT_EXPORT RenderProcessHostImpl
   // Sets this RenderProcessHost to be guest only. For Testing only.
   void SetForGuestsOnlyForTesting();
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MAC) && !defined(OS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
 #endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MAC)
