--- src/3rdparty/chromium/ui/gfx/mojo/buffer_types_struct_traits.h.orig	2020-04-05 18:58:53 UTC
+++ src/3rdparty/chromium/ui/gfx/mojo/buffer_types_struct_traits.h
@@ -193,7 +193,7 @@ struct StructTraits<gfx::mojom::GpuMemoryBufferIdDataV
   }
 };
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 template <>
 struct StructTraits<gfx::mojom::NativePixmapPlaneDataView,
                     gfx::NativePixmapPlane> {
@@ -237,7 +237,7 @@ struct StructTraits<gfx::mojom::NativePixmapHandleData
   static bool Read(gfx::mojom::NativePixmapHandleDataView data,
                    gfx::NativePixmapHandle* out);
 };
-#endif  // defined(OS_LINUX) || defined(USE_OZONE)
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 
 template <>
 struct StructTraits<gfx::mojom::GpuMemoryBufferHandleDataView,
