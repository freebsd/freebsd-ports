--- ui/gfx/mojo/buffer_types_struct_traits.cc.orig	2019-01-30 02:18:54.000000000 +0100
+++ ui/gfx/mojo/buffer_types_struct_traits.cc	2019-02-01 15:10:31.292361000 +0100
@@ -28,7 +28,7 @@
   return data.ReadUsage(&out->usage) && data.ReadFormat(&out->format);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::vector<mojo::ScopedHandle>
 StructTraits<gfx::mojom::NativePixmapHandleDataView, gfx::NativePixmapHandle>::
     fds(const gfx::NativePixmapHandle& pixmap_handle) {
@@ -55,7 +55,7 @@
   }
   return data.ReadPlanes(&out->planes);
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 gfx::mojom::GpuMemoryBufferPlatformHandlePtr StructTraits<
     gfx::mojom::GpuMemoryBufferHandleDataView,
@@ -68,7 +68,7 @@
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewSharedMemoryHandle(
           std::move(handle.region));
     case gfx::NATIVE_PIXMAP:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewNativePixmapHandle(
           handle.native_pixmap_handle);
 #else
@@ -144,7 +144,7 @@
       out->type = gfx::SHARED_MEMORY_BUFFER;
       out->region = std::move(platform_handle->get_shared_memory_handle());
       return true;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case gfx::mojom::GpuMemoryBufferPlatformHandleDataView::Tag::
         NATIVE_PIXMAP_HANDLE:
       out->type = gfx::NATIVE_PIXMAP;
