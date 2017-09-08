--- ui/gfx/mojo/buffer_types_struct_traits.cc.orig	2017-08-02 16:57:16.106307000 +0200
+++ ui/gfx/mojo/buffer_types_struct_traits.cc	2017-08-02 16:58:22.487855000 +0200
@@ -25,7 +25,7 @@
     gfx::NativePixmapHandle>::fds(const gfx::NativePixmapHandle& pixmap_handle,
                                   void* context) {
   PixmapHandleFdList* handles = static_cast<PixmapHandleFdList*>(context);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (handles->empty()) {
     // Generate the handles here, but do not send them yet.
     for (const base::FileDescriptor& fd : pixmap_handle.fds) {
@@ -34,7 +34,7 @@
     }
     return PixmapHandleFdList(handles->size());
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   return std::move(*handles);
 }
 
@@ -42,7 +42,7 @@
     gfx::mojom::NativePixmapHandleDataView,
     gfx::NativePixmapHandle>::Read(gfx::mojom::NativePixmapHandleDataView data,
                                    gfx::NativePixmapHandle* out) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   mojo::ArrayDataView<mojo::ScopedHandle> handles_data_view;
   data.GetFdsDataView(&handles_data_view);
   for (size_t i = 0; i < handles_data_view.size(); ++i) {
@@ -74,7 +74,7 @@
 StructTraits<gfx::mojom::GpuMemoryBufferHandleDataView,
              gfx::GpuMemoryBufferHandle>::
     native_pixmap_handle(const gfx::GpuMemoryBufferHandle& handle) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return handle.native_pixmap_handle;
 #else
   static gfx::NativePixmapHandle pixmap_handle;
@@ -113,7 +113,7 @@
     out->offset = data.offset();
     out->stride = data.stride();
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (out->type == gfx::NATIVE_PIXMAP &&
       !data.ReadNativePixmapHandle(&out->native_pixmap_handle))
     return false;
