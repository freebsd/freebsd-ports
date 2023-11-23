--- src/3rdparty/chromium/third_party/blink/public/platform/platform.h.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/third_party/blink/public/platform/platform.h
@@ -349,7 +349,7 @@ class BLINK_PLATFORM_EXPORT Platform {
     return nullptr;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // This is called after the thread is created, so the embedder
   // can initiate an IPC to change its thread type (on Linux we can't
   // increase the nice value, so we need to ask the browser process). This
