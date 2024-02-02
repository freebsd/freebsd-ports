--- media/gpu/chromeos/platform_video_frame_utils.cc.orig	2024-01-30 07:53:34 UTC
+++ media/gpu/chromeos/platform_video_frame_utils.cc
@@ -119,7 +119,7 @@ class GbmDeviceWrapper {
 // TODO(b/313513760): don't guard base::File::FLAG_WRITE behind
 // BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC) once the hardware video
 // decoding sandbox allows R+W access to the render nodes.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
                          // Needed on Linux for gbm_create_device().
                          | base::File::FLAG_WRITE
 #endif
