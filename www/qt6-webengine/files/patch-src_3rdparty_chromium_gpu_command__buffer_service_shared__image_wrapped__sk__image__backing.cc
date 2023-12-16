--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc
@@ -181,7 +181,7 @@ bool WrappedSkImageBacking::Initialize() {
   for (int plane = 0; plane < num_planes; ++plane) {
     auto& texture = textures_[plane];
     gfx::Size plane_size = format().GetPlaneSize(plane, size());
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Blue for single-planar and magenta-ish for multi-planar.
     SkColor4f fallback_color =
         format().is_single_plane() ? SkColors::kBlue : SkColors::kWhite;
