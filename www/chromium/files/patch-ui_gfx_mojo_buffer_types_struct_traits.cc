--- ui/gfx/mojo/buffer_types_struct_traits.cc.orig	2017-12-15 02:04:51.000000000 +0100
+++ ui/gfx/mojo/buffer_types_struct_traits.cc	2017-12-24 20:18:51.935594000 +0100
@@ -12,10 +12,10 @@
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
 
@@ -23,7 +23,7 @@
     gfx::mojom::NativePixmapHandleDataView,
     gfx::NativePixmapHandle>::Read(gfx::mojom::NativePixmapHandleDataView data,
                                    gfx::NativePixmapHandle* out) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   mojo::ArrayDataView<mojo::ScopedHandle> handles_data_view;
   data.GetFdsDataView(&handles_data_view);
   for (size_t i = 0; i < handles_data_view.size(); ++i) {
@@ -55,7 +55,7 @@
 StructTraits<gfx::mojom::GpuMemoryBufferHandleDataView,
              gfx::GpuMemoryBufferHandle>::
     native_pixmap_handle(const gfx::GpuMemoryBufferHandle& handle) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return handle.native_pixmap_handle;
 #else
   static gfx::NativePixmapHandle pixmap_handle;
@@ -94,7 +94,7 @@
     out->offset = data.offset();
     out->stride = data.stride();
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (out->type == gfx::NATIVE_PIXMAP &&
       !data.ReadNativePixmapHandle(&out->native_pixmap_handle))
     return false;
