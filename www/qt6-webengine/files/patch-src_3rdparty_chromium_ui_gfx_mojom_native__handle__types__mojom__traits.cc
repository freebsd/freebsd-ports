--- src/3rdparty/chromium/ui/gfx/mojom/native_handle_types_mojom_traits.cc.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/ui/gfx/mojom/native_handle_types_mojom_traits.cc
@@ -8,11 +8,11 @@
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 mojo::PlatformHandle StructTraits<
     gfx::mojom::NativePixmapPlaneDataView,
     gfx::NativePixmapPlane>::buffer_handle(gfx::NativePixmapPlane& plane) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return mojo::PlatformHandle(std::move(plane.fd));
 #elif BUILDFLAG(IS_FUCHSIA)
   return mojo::PlatformHandle(std::move(plane.vmo));
@@ -28,7 +28,7 @@ bool StructTraits<
   out->size = data.size();
 
   mojo::PlatformHandle handle = data.TakeBufferHandle();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!handle.is_fd())
     return false;
   out->fd = handle.TakeFD();
@@ -54,7 +54,7 @@ bool StructTraits<
     gfx::mojom::NativePixmapHandleDataView,
     gfx::NativePixmapHandle>::Read(gfx::mojom::NativePixmapHandleDataView data,
                                    gfx::NativePixmapHandle* out) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   out->modifier = data.modifier();
   out->supports_zero_copy_webgpu_import =
       data.supports_zero_copy_webgpu_import();
