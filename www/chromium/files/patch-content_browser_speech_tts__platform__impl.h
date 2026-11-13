--- content/browser/speech/tts_platform_impl.h.orig	2026-11-11 14:44:17 UTC
+++ content/browser/speech/tts_platform_impl.h
@@ -15,7 +15,7 @@
 
 namespace content {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Overrides the library path captured when the Linux TTS singleton is created.
 // Must be called before TtsPlatform::GetInstance().
 CONTENT_EXPORT base::AutoReset<std::string>
