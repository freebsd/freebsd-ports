--- components/media_router/common/media_source.cc.orig	2025-03-05 08:14:56 UTC
+++ components/media_router/common/media_source.cc
@@ -62,7 +62,7 @@ bool IsSystemAudioCaptureSupported() {
   if (!media::IsSystemLoopbackCaptureSupported()) {
     return false;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
 #else
   return true;
