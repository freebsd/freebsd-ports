--- ui/gfx/mojom/buffer_types_mojom_traits.cc.orig	2019-10-30 16:33:03 UTC
+++ ui/gfx/mojom/buffer_types_mojom_traits.cc
@@ -24,15 +24,15 @@ bool StructTraits<gfx::mojom::BufferUsageAndFormatData
   return data.ReadUsage(&out->usage) && data.ReadFormat(&out->format);
 }
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 mojo::ScopedHandle StructTraits<
     gfx::mojom::NativePixmapPlaneDataView,
     gfx::NativePixmapPlane>::buffer_handle(gfx::NativePixmapPlane& plane) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return mojo::WrapPlatformFile(plane.fd.release());
 #elif defined(OS_FUCHSIA)
   return mojo::WrapPlatformHandle(mojo::PlatformHandle(std::move(plane.vmo)));
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 bool StructTraits<
@@ -45,7 +45,7 @@ bool StructTraits<
 
   mojo::PlatformHandle handle =
       mojo::UnwrapPlatformHandle(data.TakeBufferHandle());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!handle.is_fd())
     return false;
   out->fd = handle.TakeFD();
@@ -53,7 +53,7 @@ bool StructTraits<
   if (!handle.is_handle())
     return false;
   out->vmo = zx::vmo(handle.TakeHandle());
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   return true;
 }
@@ -62,7 +62,7 @@ bool StructTraits<
     gfx::mojom::NativePixmapHandleDataView,
     gfx::NativePixmapHandle>::Read(gfx::mojom::NativePixmapHandleDataView data,
                                    gfx::NativePixmapHandle* out) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   out->modifier = data.modifier();
 #endif
 
@@ -75,7 +75,7 @@ bool StructTraits<
 
   return data.ReadPlanes(&out->planes);
 }
-#endif  // defined(OS_LINUX) || defined(USE_OZONE)
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 
 gfx::mojom::GpuMemoryBufferPlatformHandlePtr StructTraits<
     gfx::mojom::GpuMemoryBufferHandleDataView,
@@ -88,7 +88,7 @@ gfx::mojom::GpuMemoryBufferPlatformHandlePtr StructTra
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewSharedMemoryHandle(
           std::move(handle.region));
     case gfx::NATIVE_PIXMAP:
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewNativePixmapHandle(
           std::move(handle.native_pixmap_handle));
 #else
@@ -164,7 +164,7 @@ bool StructTraits<gfx::mojom::GpuMemoryBufferHandleDat
       out->type = gfx::SHARED_MEMORY_BUFFER;
       out->region = std::move(platform_handle->get_shared_memory_handle());
       return true;
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
     case gfx::mojom::GpuMemoryBufferPlatformHandleDataView::Tag::
         NATIVE_PIXMAP_HANDLE:
       out->type = gfx::NATIVE_PIXMAP;
