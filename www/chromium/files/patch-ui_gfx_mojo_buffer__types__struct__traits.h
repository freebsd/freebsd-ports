--- ui/gfx/mojo/buffer_types_struct_traits.h.orig	2019-07-24 18:59:22 UTC
+++ ui/gfx/mojo/buffer_types_struct_traits.h
@@ -188,7 +188,7 @@ struct StructTraits<gfx::mojom::GpuMemoryBufferIdDataV
   }
 };
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
 template <>
 struct StructTraits<gfx::mojom::NativePixmapPlaneDataView,
                     gfx::NativePixmapPlane> {
@@ -232,7 +232,7 @@ struct StructTraits<gfx::mojom::NativePixmapHandleData
   static bool Read(gfx::mojom::NativePixmapHandleDataView data,
                    gfx::NativePixmapHandle* out);
 };
-#endif  // defined(OS_LINUX) || defined(USE_OZONE)
+#endif  // defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
 
 template <>
 struct StructTraits<gfx::mojom::GpuMemoryBufferHandleDataView,
