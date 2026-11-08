--- src/3rdparty/chromium/components/media_router/common/media_source.cc.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/components/media_router/common/media_source.cc
@@ -68,7 +68,7 @@ bool IsSystemAudioCaptureSupported() {
 #if BUILDFLAG(IS_MAC)
   return media::IsMacSckSystemLoopbackCaptureSupported() ||
          base::FeatureList::IsEnabled(media::kMacCatapLoopbackAudioForCast);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
   return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
 #else
   return true;
