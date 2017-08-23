--- content/browser/renderer_host/render_process_host_impl.h.orig	2017-08-02 01:07:45.102330000 +0200
+++ content/browser/renderer_host/render_process_host_impl.h	2017-08-02 01:09:10.056596000 +0200
@@ -290,10 +290,10 @@
     is_for_guests_only_ = is_for_guests_only;
   }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   void RecomputeAndUpdateWebKitPreferences();
 
