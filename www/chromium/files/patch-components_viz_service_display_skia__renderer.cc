--- components/viz/service/display/skia_renderer.cc.orig	2026-08-31 10:59:09 UTC
+++ components/viz/service/display/skia_renderer.cc
@@ -1433,7 +1433,7 @@ void SkiaRenderer::ClearFramebuffer() {
   if (current_frame()->current_render_pass->has_transparent_background) {
     ClearCanvas(SkColors::kTransparent);
   } else {
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // On DEBUG builds, opaque render passes are cleared to blue
     // to easily see regions that were not drawn on the screen.
     // ClearCavas() call causes slight pixel difference, so linux-ref and
