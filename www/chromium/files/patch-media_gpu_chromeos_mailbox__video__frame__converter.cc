--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2025-10-30 15:44:36 UTC
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -226,7 +226,7 @@ MailboxVideoFrameConverter::GenerateSharedImage(
                            VideoPixelFormatToString(origin_frame->format()));
     return nullptr;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (si_format->is_multi_plane()) {
