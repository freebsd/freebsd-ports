--- device/vr/openxr/openxr_graphics_binding.cc.orig	2026-11-19 12:25:27 UTC
+++ device/vr/openxr/openxr_graphics_binding.cc
@@ -309,7 +309,7 @@ bool OpenXrGraphicsBinding::WaitOnBaseLayerFence(gfx::
   return WaitOnFence(*base_layer_, gpu_fence);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpenXrGraphicsBinding::WaitOnImplicitFences(
     const std::vector<LayerId>& updated_layers) {
   if (layers_sequence_.empty()) {
@@ -565,7 +565,7 @@ bool OpenXrGraphicsBinding::CreateCompositionLayer(
   if (!SupportsLayers()) {
     return false;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The page's layer of an unsupported type never becomes active.
   if (!SupportsLayerType(OpenXrCompositionLayer::GetTypeFromMojomData(
           *layer_data->mutable_data->layer_data))) {
