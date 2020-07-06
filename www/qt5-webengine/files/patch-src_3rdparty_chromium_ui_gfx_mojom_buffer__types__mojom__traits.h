--- src/3rdparty/chromium/ui/gfx/mojom/buffer_types_mojom_traits.h.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/ui/gfx/mojom/buffer_types_mojom_traits.h
@@ -194,7 +194,7 @@ struct StructTraits<gfx::mojom::GpuMemoryBufferIdDataV
   }
 };
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 template <>
 struct StructTraits<gfx::mojom::NativePixmapPlaneDataView,
                     gfx::NativePixmapPlane> {
@@ -220,7 +220,7 @@ struct StructTraits<gfx::mojom::NativePixmapHandleData
     return pixmap_handle.planes;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   static uint64_t modifier(const gfx::NativePixmapHandle& pixmap_handle) {
     return pixmap_handle.modifier;
   }
@@ -244,7 +244,7 @@ struct StructTraits<gfx::mojom::NativePixmapHandleData
   static bool Read(gfx::mojom::NativePixmapHandleDataView data,
                    gfx::NativePixmapHandle* out);
 };
-#endif  // defined(OS_LINUX) || defined(USE_OZONE)
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 
 template <>
 struct StructTraits<gfx::mojom::GpuMemoryBufferHandleDataView,
