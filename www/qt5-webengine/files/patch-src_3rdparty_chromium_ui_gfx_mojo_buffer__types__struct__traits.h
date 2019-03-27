--- src/3rdparty/chromium/ui/gfx/mojo/buffer_types_struct_traits.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/gfx/mojo/buffer_types_struct_traits.h
@@ -291,7 +291,7 @@ template <>
 struct StructTraits<gfx::mojom::NativePixmapHandleDataView,
                     gfx::NativePixmapHandle> {
   static bool IsNull(const gfx::NativePixmapHandle& handle) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return false;
 #else
     // NativePixmapHandle are not used on non-linux platforms.
