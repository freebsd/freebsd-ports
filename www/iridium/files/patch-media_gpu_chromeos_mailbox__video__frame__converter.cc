--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2026-04-15 12:07:04 UTC
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -249,7 +249,7 @@ MailboxVideoFrameConverter::GenerateSharedImage(
                            VideoPixelFormatToString(origin_frame->format()));
     return nullptr;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (si_format->is_multi_plane()) {
