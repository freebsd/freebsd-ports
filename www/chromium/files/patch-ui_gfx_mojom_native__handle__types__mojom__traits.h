--- ui/gfx/mojom/native_handle_types_mojom_traits.h.orig	2025-07-02 06:08:04 UTC
+++ ui/gfx/mojom/native_handle_types_mojom_traits.h
@@ -18,7 +18,7 @@
 #include "ui/gfx/gpu_memory_buffer.h"
 #include "ui/gfx/mojom/native_handle_types.mojom-shared.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
 
@@ -46,7 +46,7 @@ struct COMPONENT_EXPORT(GFX_NATIVE_HANDLE_TYPES_SHARED
 };
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 template <>
 struct COMPONENT_EXPORT(GFX_NATIVE_HANDLE_TYPES_SHARED_MOJOM_TRAITS)
     StructTraits<gfx::mojom::NativePixmapPlaneDataView,
@@ -74,13 +74,13 @@ struct COMPONENT_EXPORT(GFX_NATIVE_HANDLE_TYPES_SHARED
     return pixmap_handle.planes;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static uint64_t modifier(const gfx::NativePixmapHandle& pixmap_handle) {
     return pixmap_handle.modifier;
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static bool supports_zero_copy_webgpu_import(
       const gfx::NativePixmapHandle& pixmap_handle) {
     return pixmap_handle.supports_zero_copy_webgpu_import;
@@ -159,7 +159,7 @@ struct COMPONENT_EXPORT(GFX_NATIVE_HANDLE_TYPES_SHARED
   static PlatformHandle mach_port(gfx::GpuMemoryBufferHandle& handle);
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
   static gfx::NativePixmapHandle& native_pixmap_handle(
       gfx::GpuMemoryBufferHandle& handle) {
     return handle.native_pixmap_handle_;
