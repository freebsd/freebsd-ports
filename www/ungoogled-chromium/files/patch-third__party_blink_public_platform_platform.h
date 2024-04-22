--- third_party/blink/public/platform/platform.h.orig	2024-04-12 16:47:26 UTC
+++ third_party/blink/public/platform/platform.h
@@ -252,7 +252,7 @@ class BLINK_PLATFORM_EXPORT Platform {
   virtual viz::FrameSinkId GenerateFrameSinkId() { return viz::FrameSinkId(); }
 
   // Returns whether this process is locked to a single site (i.e. a scheme
-  // plus eTLD+1, such as https://9oo91e.qjz9zk), or to a more specific origin.
+  // plus eTLD+1, such as https://google.com), or to a more specific origin.
   // This means the process will not be used to load documents or workers from
   // URLs outside that site.
   virtual bool IsLockedToSite() const { return false; }
@@ -347,7 +347,7 @@ class BLINK_PLATFORM_EXPORT Platform {
     return nullptr;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // This is called after the thread is created, so the embedder
   // can initiate an IPC to change its thread type (on Linux we can't
   // increase the nice value, so we need to ask the browser process). This
