--- ui/gfx/mojom/native_handle_types_mojom_traits.h.orig	2022-02-28 16:54:41 UTC
+++ ui/gfx/mojom/native_handle_types_mojom_traits.h
@@ -15,7 +15,7 @@
 #include "third_party/abseil-cpp/absl/types/optional.h"
 #include "ui/gfx/mojom/native_handle_types.mojom-shared.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #endif
 
@@ -25,7 +25,7 @@
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
 template <>
 struct COMPONENT_EXPORT(GFX_NATIVE_HANDLE_TYPES_SHARED_MOJOM_TRAITS)
     StructTraits<gfx::mojom::NativePixmapPlaneDataView,
@@ -53,7 +53,7 @@ struct COMPONENT_EXPORT(GFX_NATIVE_HANDLE_TYPES_SHARED
     return pixmap_handle.planes;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static uint64_t modifier(const gfx::NativePixmapHandle& pixmap_handle) {
     return pixmap_handle.modifier;
   }
