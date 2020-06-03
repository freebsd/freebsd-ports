--- ui/gfx/mojom/native_handle_types_mojom_traits.cc.orig	2020-05-15 15:28:55 UTC
+++ ui/gfx/mojom/native_handle_types_mojom_traits.cc
@@ -8,15 +8,15 @@
 
 namespace mojo {
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 mojo::PlatformHandle StructTraits<
     gfx::mojom::NativePixmapPlaneDataView,
     gfx::NativePixmapPlane>::buffer_handle(gfx::NativePixmapPlane& plane) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return mojo::PlatformHandle(std::move(plane.fd));
 #elif defined(OS_FUCHSIA)
   return mojo::PlatformHandle(std::move(plane.vmo));
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 bool StructTraits<
@@ -28,7 +28,7 @@ bool StructTraits<
   out->size = data.size();
 
   mojo::PlatformHandle handle = data.TakeBufferHandle();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!handle.is_fd())
     return false;
   out->fd = handle.TakeFD();
@@ -36,7 +36,7 @@ bool StructTraits<
   if (!handle.is_handle())
     return false;
   out->vmo = zx::vmo(handle.TakeHandle());
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   return true;
 }
@@ -45,7 +45,7 @@ bool StructTraits<
     gfx::mojom::NativePixmapHandleDataView,
     gfx::NativePixmapHandle>::Read(gfx::mojom::NativePixmapHandleDataView data,
                                    gfx::NativePixmapHandle* out) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   out->modifier = data.modifier();
 #endif
 
@@ -58,6 +58,6 @@ bool StructTraits<
 
   return data.ReadPlanes(&out->planes);
 }
-#endif  // defined(OS_LINUX) || defined(USE_OZONE)
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 
 }  // namespace mojo
