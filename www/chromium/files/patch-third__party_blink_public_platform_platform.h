--- third_party/blink/public/platform/platform.h.orig	2021-09-14 01:52:02 UTC
+++ third_party/blink/public/platform/platform.h
@@ -421,7 +421,7 @@ class BLINK_PLATFORM_EXPORT Platform {
     return nullptr;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // This is called after the compositor thread is created, so the embedder
   // can initiate an IPC to change its thread priority (on Linux we can't
   // increase the nice value, so we need to ask the browser process). This
