--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2023-11-22 14:00:11 UTC
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -59,7 +59,7 @@ viz::SharedImageFormat GetSharedImageFormat(gfx::Buffe
                     << static_cast<int>(buffer_format);
       NOTREACHED_NORETURN();
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (format.is_multi_plane()) {
