--- src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.h
@@ -466,7 +466,7 @@ class CONTENT_EXPORT RenderProcessHostImpl
   // Sets this RenderProcessHost to be guest only. For Testing only.
   void SetForGuestsOnlyForTesting();
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
