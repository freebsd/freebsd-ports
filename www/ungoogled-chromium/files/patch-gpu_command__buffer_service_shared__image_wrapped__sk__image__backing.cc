--- gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc.orig	2023-05-05 12:12:41 UTC
+++ gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc
@@ -198,7 +198,7 @@ bool WrappedSkImageBacking::Initialize() {
 
     constexpr GrRenderable is_renderable = GrRenderable::kYes;
     constexpr GrProtected is_protected = GrProtected::kNo;
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Blue for single-planar and magenta-ish for multi-planar.
     SkColor4f fallback_color =
         format().is_single_plane() ? SkColors::kBlue : SkColors::kWhite;
