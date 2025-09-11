--- components/media_router/common/media_source.cc.orig	2025-09-06 10:01:20 UTC
+++ components/media_router/common/media_source.cc
@@ -62,7 +62,7 @@ bool IsSystemAudioCaptureSupported() {
 #if BUILDFLAG(IS_MAC)
   return media::IsMacSckSystemLoopbackCaptureSupported() ||
          base::FeatureList::IsEnabled(media::kMacCatapLoopbackAudioForCast);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
   return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
 #else
   return true;
