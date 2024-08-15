--- components/viz/common/features.h.orig	2024-08-01 05:47:53 UTC
+++ components/viz/common/features.h
@@ -75,7 +75,7 @@ VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kDrawPredictedI
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kAllowUndamagedNonrootRenderPassToSkip);
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(
     kAllowForceMergeRenderPassWithRequireOverlayQuads);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kRendererAllocatesImages);
 #endif
 VIZ_COMMON_EXPORT BASE_DECLARE_FEATURE(kBufferQueueImageSetPurgeable);
@@ -136,7 +136,7 @@ VIZ_COMMON_EXPORT std::optional<double> IsDynamicSched
 VIZ_COMMON_EXPORT std::optional<double> IsDynamicSchedulerEnabledForClients();
 VIZ_COMMON_EXPORT int MaxOverlaysConsidered();
 VIZ_COMMON_EXPORT bool ShouldOnBeginFrameThrottleVideo();
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 VIZ_COMMON_EXPORT bool ShouldRendererAllocateImages();
 #endif
 VIZ_COMMON_EXPORT bool IsOnBeginFrameAcksEnabled();
