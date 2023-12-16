--- src/3rdparty/chromium/ui/gfx/mojom/buffer_types_mojom_traits.cc.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/ui/gfx/mojom/buffer_types_mojom_traits.cc
@@ -33,7 +33,7 @@ gfx::mojom::GpuMemoryBufferPlatformHandlePtr StructTra
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewSharedMemoryHandle(
           std::move(handle.region));
     case gfx::NATIVE_PIXMAP:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewNativePixmapHandle(
           std::move(handle.native_pixmap_handle));
 #else
@@ -115,7 +115,7 @@ bool StructTraits<gfx::mojom::GpuMemoryBufferHandleDat
       out->type = gfx::SHARED_MEMORY_BUFFER;
       out->region = std::move(platform_handle->get_shared_memory_handle());
       return true;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
     case gfx::mojom::GpuMemoryBufferPlatformHandleDataView::Tag::
         kNativePixmapHandle:
       out->type = gfx::NATIVE_PIXMAP;
