--- src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.h
@@ -348,10 +348,10 @@ class CONTENT_EXPORT RenderProcessHostImpl
     is_for_guests_only_ = is_for_guests_only;
   }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   void RecomputeAndUpdateWebKitPreferences();
 
