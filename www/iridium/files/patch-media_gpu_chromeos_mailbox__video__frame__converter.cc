--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2026-02-16 10:45:29 UTC
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -224,7 +224,7 @@ MailboxVideoFrameConverter::GenerateSharedImage(
                            VideoPixelFormatToString(origin_frame->format()));
     return nullptr;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (si_format->is_multi_plane()) {
