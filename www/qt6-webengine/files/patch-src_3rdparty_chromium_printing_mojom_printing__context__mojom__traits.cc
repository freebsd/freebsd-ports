--- src/3rdparty/chromium/printing/mojom/printing_context_mojom_traits.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/printing/mojom/printing_context_mojom_traits.cc
@@ -15,7 +15,7 @@
 #include "ui/gfx/geometry/mojom/geometry_mojom_traits.h"
 #include "ui/gfx/geometry/size.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "mojo/public/mojom/base/values.mojom.h"
 #endif
 
@@ -150,7 +150,7 @@ bool StructTraits<
   }
 
   out->set_pages_per_sheet(data.pages_per_sheet());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   DCHECK(out->advanced_settings().empty());
   if (!data.ReadAdvancedSettings(&out->advanced_settings()))
     return false;
