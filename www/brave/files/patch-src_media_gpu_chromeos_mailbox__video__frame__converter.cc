--- src/media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2026-10-18 18:43:23 UTC
+++ src/media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -231,7 +231,7 @@ MailboxVideoFrameConverter::GenerateShar
                            VideoPixelFormatToString(origin_frame->format()));
     return nullptr;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (si_format->is_multi_plane()) {
