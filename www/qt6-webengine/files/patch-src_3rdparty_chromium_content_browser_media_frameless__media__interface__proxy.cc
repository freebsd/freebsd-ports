--- src/3rdparty/chromium/content/browser/media/frameless_media_interface_proxy.cc.orig	2022-08-31 12:19:35 UTC
+++ src/3rdparty/chromium/content/browser/media/frameless_media_interface_proxy.cc
@@ -16,7 +16,7 @@
 #include "media/mojo/mojom/renderer_extensions.mojom.h"
 #include "media/mojo/mojom/stable/stable_video_decoder.mojom.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/public/browser/stable_video_decoder_factory.h"
 #include "media/base/media_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -67,7 +67,7 @@ void FramelessMediaInterfaceProxy::CreateVideoDecoder(
 
   mojo::PendingRemote<media::stable::mojom::StableVideoDecoder>
       oop_video_decoder;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseOutOfProcessVideoDecoding)) {
     if (!render_process_host_) {
       if (!stable_vd_factory_remote_.is_bound()) {
