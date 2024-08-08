--- content/browser/gpu/compositor_util.cc.orig	2024-08-01 05:47:53 UTC
+++ content/browser/gpu/compositor_util.cc
@@ -154,7 +154,7 @@ std::vector<GpuFeatureData> GetGpuFeatureData(
       "video_decode",
       SafeGetFeatureStatus(
           gpu_feature_info, gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           !base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) ||
 #endif  // BUILDFLAG(IS_LINUX)
               command_line.HasSwitch(switches::kDisableAcceleratedVideoDecode)),
@@ -166,7 +166,7 @@ std::vector<GpuFeatureData> GetGpuFeatureData(
       "video_encode",
       SafeGetFeatureStatus(
           gpu_feature_info, gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_ENCODE,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           !base::FeatureList::IsEnabled(media::kVaapiVideoEncodeLinux)),
 #else
           command_line.HasSwitch(switches::kDisableAcceleratedVideoEncode)),
