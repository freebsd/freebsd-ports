--- gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc.orig	2023-03-13 07:33:08 UTC
+++ gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc
@@ -186,7 +186,7 @@ bool WrappedSkImageBacking::Initialize() {
                                                     : GrMipMapped::kNo;
   const std::string label = "WrappedSkImageBackingFactory_Initialize" +
                             CreateLabelForSharedImageUsage(usage());
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Initializing to bright green makes it obvious if the pixels are not
   // properly set before they are displayed (e.g. https://crbug.com/956555).
   // We don't do this on release builds because there is a slight overhead.
