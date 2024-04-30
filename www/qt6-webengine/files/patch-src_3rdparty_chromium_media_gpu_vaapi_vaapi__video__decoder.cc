--- src/3rdparty/chromium/media/gpu/vaapi/vaapi_video_decoder.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/media/gpu/vaapi/vaapi_video_decoder.cc
@@ -782,7 +782,7 @@ void VaapiVideoDecoder::ApplyResolutionChangeWithScree
   const gfx::Size decoder_natural_size =
       aspect_ratio_.GetNaturalSize(decoder_visible_rect);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   absl::optional<DmabufVideoFramePool::CreateFrameCB> allocator =
       base::BindRepeating(&AllocateCustomFrameProxy, weak_this_);
   std::vector<ImageProcessor::PixelLayoutCandidate> candidates = {
