--- device/vr/openxr/openxr_graphics_binding.h.orig	2026-11-19 12:25:27 UTC
+++ device/vr/openxr/openxr_graphics_binding.h
@@ -142,7 +142,7 @@ class OpenXrGraphicsBinding {
   // Return if the graphics binding supports multiple XR layers.
   virtual bool SupportsLayers() const = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Return if the graphics binding can create layers of the given type.
   virtual bool SupportsLayerType(OpenXrCompositionLayer::Type type) const = 0;
 #endif
@@ -213,7 +213,7 @@ class OpenXrGraphicsBinding {
   // able to successfully schedule and perform the wait, and false otherwise.
   bool WaitOnBaseLayerFence(gfx::GpuFence& gpu_fence);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Waits on the fences that the shared images of `updated_layers` carry for
   // the writes to them. Returns false if there are none.
   bool WaitOnImplicitFences(const std::vector<LayerId>& updated_layers);
@@ -286,7 +286,7 @@ class OpenXrGraphicsBinding {
   virtual bool WaitOnFence(OpenXrCompositionLayer& layer,
                            gfx::GpuFence& gpu_fence) = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // As WaitOnImplicitFences(), for `layer`'s active shared image.
   virtual bool WaitOnImplicitFence(OpenXrCompositionLayer& layer) = 0;
 #endif
