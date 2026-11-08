--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2026-08-31 10:59:09 UTC
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -232,7 +232,7 @@ MailboxVideoFrameConverter::GenerateSharedImage(
                            VideoPixelFormatToString(origin_frame->format()));
     return nullptr;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (si_format->is_multi_plane()) {
