--- components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2020-03-17 09:50:06 UTC
+++ components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -224,7 +224,7 @@ void SkiaOutputSurfaceImpl::Reshape(const gfx::Size& s
   if (characterization_.isValid()) {
     // TODO(vasilyt): We temporary keep old code for linux to not interferee
     // with M81. Remove this after.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     sk_sp<SkColorSpace> sk_color_space = color_space.ToSkColorSpace();
     if (!SkColorSpace::Equals(characterization_.colorSpace(),
                               sk_color_space.get())) {
