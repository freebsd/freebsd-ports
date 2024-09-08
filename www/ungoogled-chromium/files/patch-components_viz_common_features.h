--- components/viz/common/features.h.orig	2024-08-26 14:40:28 UTC
+++ components/viz/common/features.h
@@ -72,7 +72,7 @@ VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kDrawPredictedI
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kAllowUndamagedNonrootRenderPassToSkip);
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(
     kAllowForceMergeRenderPassWithRequireOverlayQuads);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kRendererAllocatesImages);
 #endif
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kOnBeginFrameAcks);
@@ -129,7 +129,7 @@ VIZ_COMMON_EXPORT bool UseWebViewNewInvalidateHeuristi
 VIZ_COMMON_EXPORT bool UseSurfaceLayerForVideo();
 VIZ_COMMON_EXPORT int MaxOverlaysConsidered();
 VIZ_COMMON_EXPORT bool ShouldOnBeginFrameThrottleVideo();
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 VIZ_COMMON_EXPORT bool ShouldRendererAllocateImages();
 #endif
 VIZ_COMMON_EXPORT bool IsOnBeginFrameAcksEnabled();
