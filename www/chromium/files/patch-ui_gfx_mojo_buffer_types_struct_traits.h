--- ui/gfx/mojo/buffer_types_struct_traits.h.orig	2019-01-30 02:18:54.000000000 +0100
+++ ui/gfx/mojo/buffer_types_struct_traits.h	2019-02-01 15:19:04.908647000 +0100
@@ -189,7 +189,7 @@
   }
 };
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 template <>
 struct StructTraits<gfx::mojom::NativePixmapPlaneDataView,
                     gfx::NativePixmapPlane> {
@@ -229,7 +229,7 @@
   static bool Read(gfx::mojom::NativePixmapHandleDataView data,
                    gfx::NativePixmapHandle* out);
 };
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 template <>
 struct StructTraits<gfx::mojom::GpuMemoryBufferHandleDataView,
