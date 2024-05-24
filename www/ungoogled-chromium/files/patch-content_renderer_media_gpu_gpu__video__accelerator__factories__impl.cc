--- content/renderer/media/gpu/gpu_video_accelerator_factories_impl.cc.orig	2024-05-23 20:04:36 UTC
+++ content/renderer/media/gpu/gpu_video_accelerator_factories_impl.cc
@@ -57,7 +57,7 @@ bool UseSingleNV12() {
 #else
   static BASE_FEATURE(kUseSingleNV12ForSoftwareGMB,
                       "UseSingleNV12ForSoftwareGMB",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                       base::FEATURE_ENABLED_BY_DEFAULT);
 #else
                       base::FEATURE_DISABLED_BY_DEFAULT);
