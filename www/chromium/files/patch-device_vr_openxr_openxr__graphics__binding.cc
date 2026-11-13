--- device/vr/openxr/openxr_graphics_binding.cc.orig	2026-11-11 14:44:17 UTC
+++ device/vr/openxr/openxr_graphics_binding.cc
@@ -301,7 +301,7 @@ bool OpenXrGraphicsBinding::WaitOnBaseLayerFence(gfx::
   return WaitOnFence(*base_layer_, gpu_fence);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpenXrGraphicsBinding::WaitOnImplicitFences(
     const std::vector<LayerId>& updated_layers) {
   if (layers_sequence_.empty()) {
