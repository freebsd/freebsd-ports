--- src/3rdparty/chromium/content/browser/media/media_interface_proxy.cc.orig	2022-10-24 13:33:33 UTC
+++ src/3rdparty/chromium/content/browser/media/media_interface_proxy.cc
@@ -73,7 +73,7 @@
 #include "media/mojo/services/mojo_renderer_service.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/public/browser/stable_video_decoder_factory.h"
 #include "media/base/media_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -286,7 +286,7 @@ void MediaInterfaceProxy::CreateVideoDecoder(
 
   mojo::PendingRemote<media::stable::mojom::StableVideoDecoder>
       oop_video_decoder;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseOutOfProcessVideoDecoding)) {
     render_frame_host().GetProcess()->CreateStableVideoDecoder(
         oop_video_decoder.InitWithNewPipeAndPassReceiver());
