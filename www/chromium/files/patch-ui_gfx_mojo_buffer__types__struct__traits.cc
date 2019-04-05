--- ui/gfx/mojo/buffer_types_struct_traits.cc.orig	2019-03-11 22:01:19 UTC
+++ ui/gfx/mojo/buffer_types_struct_traits.cc
@@ -28,7 +28,7 @@ bool StructTraits<gfx::mojom::BufferUsageAndFormatData
   return data.ReadUsage(&out->usage) && data.ReadFormat(&out->format);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::vector<mojo::ScopedHandle>
 StructTraits<gfx::mojom::NativePixmapHandleDataView, gfx::NativePixmapHandle>::
     fds(const gfx::NativePixmapHandle& pixmap_handle) {
@@ -55,7 +55,7 @@ bool StructTraits<
   }
   return data.ReadPlanes(&out->planes);
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 gfx::mojom::GpuMemoryBufferPlatformHandlePtr StructTraits<
     gfx::mojom::GpuMemoryBufferHandleDataView,
@@ -68,7 +68,7 @@ gfx::mojom::GpuMemoryBufferPlatformHandlePtr StructTra
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewSharedMemoryHandle(
           std::move(handle.region));
     case gfx::NATIVE_PIXMAP:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewNativePixmapHandle(
           handle.native_pixmap_handle);
 #else
@@ -144,7 +144,7 @@ bool StructTraits<gfx::mojom::GpuMemoryBufferHandleDat
       out->type = gfx::SHARED_MEMORY_BUFFER;
       out->region = std::move(platform_handle->get_shared_memory_handle());
       return true;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case gfx::mojom::GpuMemoryBufferPlatformHandleDataView::Tag::
         NATIVE_PIXMAP_HANDLE:
       out->type = gfx::NATIVE_PIXMAP;
