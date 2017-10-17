--- ui/gfx/mojo/buffer_types_struct_traits.cc.orig	2017-09-05 21:05:48.000000000 +0200
+++ ui/gfx/mojo/buffer_types_struct_traits.cc	2017-09-07 01:52:13.480533000 +0200
@@ -12,10 +12,10 @@
                    gfx::NativePixmapHandle>::
     SetUpContext(const gfx::NativePixmapHandle& pixmap_handle) {
   auto* handles = new std::vector<mojo::ScopedHandle>();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   for (const base::FileDescriptor& fd : pixmap_handle.fds)
     handles->emplace_back(mojo::WrapPlatformFile(fd.fd));
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   return handles;
 }
 
@@ -36,7 +36,7 @@
     gfx::mojom::NativePixmapHandleDataView,
     gfx::NativePixmapHandle>::Read(gfx::mojom::NativePixmapHandleDataView data,
                                    gfx::NativePixmapHandle* out) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   mojo::ArrayDataView<mojo::ScopedHandle> handles_data_view;
   data.GetFdsDataView(&handles_data_view);
   for (size_t i = 0; i < handles_data_view.size(); ++i) {
@@ -68,7 +68,7 @@
 StructTraits<gfx::mojom::GpuMemoryBufferHandleDataView,
              gfx::GpuMemoryBufferHandle>::
     native_pixmap_handle(const gfx::GpuMemoryBufferHandle& handle) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return handle.native_pixmap_handle;
 #else
   static gfx::NativePixmapHandle pixmap_handle;
@@ -107,7 +107,7 @@
     out->offset = data.offset();
     out->stride = data.stride();
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (out->type == gfx::NATIVE_PIXMAP &&
       !data.ReadNativePixmapHandle(&out->native_pixmap_handle))
     return false;
