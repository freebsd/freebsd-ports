--- media/webrtc/helpers.cc.orig	2023-01-13 08:56:02 UTC
+++ media/webrtc/helpers.cc
@@ -17,14 +17,14 @@
 namespace media {
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr bool kUseHybridAgc = true;
 #else
 constexpr bool kUseHybridAgc = false;
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr bool kUseClippingController = true;
 #else
 constexpr bool kUseClippingController = false;
