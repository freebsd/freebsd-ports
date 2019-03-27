--- src/3rdparty/chromium/ui/gfx/mojo/buffer_types_struct_traits.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/gfx/mojo/buffer_types_struct_traits.cc
@@ -27,10 +27,10 @@ std::vector<mojo::ScopedHandle>
 StructTraits<gfx::mojom::NativePixmapHandleDataView, gfx::NativePixmapHandle>::
     fds(const gfx::NativePixmapHandle& pixmap_handle) {
   std::vector<mojo::ScopedHandle> handles;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   for (const base::FileDescriptor& fd : pixmap_handle.fds)
     handles.emplace_back(mojo::WrapPlatformFile(fd.fd));
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   return handles;
 }
 
@@ -38,7 +38,7 @@ bool StructTraits<
     gfx::mojom::NativePixmapHandleDataView,
     gfx::NativePixmapHandle>::Read(gfx::mojom::NativePixmapHandleDataView data,
                                    gfx::NativePixmapHandle* out) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   mojo::ArrayDataView<mojo::ScopedHandle> handles_data_view;
   data.GetFdsDataView(&handles_data_view);
   for (size_t i = 0; i < handles_data_view.size(); ++i) {
@@ -71,7 +71,7 @@ const gfx::NativePixmapHandle&
 StructTraits<gfx::mojom::GpuMemoryBufferHandleDataView,
              gfx::GpuMemoryBufferHandle>::
     native_pixmap_handle(const gfx::GpuMemoryBufferHandle& handle) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return handle.native_pixmap_handle;
 #else
   static gfx::NativePixmapHandle pixmap_handle;
@@ -154,7 +154,7 @@ bool StructTraits<gfx::mojom::GpuMemoryBufferHandleDat
     out->offset = data.offset();
     out->stride = data.stride();
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (out->type == gfx::NATIVE_PIXMAP &&
       !data.ReadNativePixmapHandle(&out->native_pixmap_handle))
     return false;
