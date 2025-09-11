--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2025-09-10 13:22:16 UTC
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -321,7 +321,7 @@ bool MailboxVideoFrameConverter::GenerateSharedImage(
                            VideoPixelFormatToString(origin_frame->format()));
     return false;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (si_format->is_multi_plane()) {
