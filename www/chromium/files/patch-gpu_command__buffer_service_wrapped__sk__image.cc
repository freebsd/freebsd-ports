--- gpu/command_buffer/service/wrapped_sk_image.cc.orig	2022-07-22 17:30:31 UTC
+++ gpu/command_buffer/service/wrapped_sk_image.cc
@@ -277,7 +277,7 @@ class WrappedSkImage : public ClearTrackingSharedImage
     DCHECK_NE(format(), viz::ResourceFormat::ETC1);
     auto mipmap = usage() & SHARED_IMAGE_USAGE_MIPMAP ? GrMipMapped::kYes
                                                       : GrMipMapped::kNo;
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Initializing to bright green makes it obvious if the pixels are not
     // properly set before they are displayed (e.g. https://crbug.com/956555).
     // We don't do this on release builds because there is a slight overhead.
