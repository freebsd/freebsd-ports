--- printing/mojom/printing_context_mojom_traits.cc.orig	2021-12-16 15:15:32 UTC
+++ printing/mojom/printing_context_mojom_traits.cc
@@ -16,7 +16,7 @@
 #include "ui/gfx/geometry/mojom/geometry_mojom_traits.h"
 #include "ui/gfx/geometry/size.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "mojo/public/mojom/base/values.mojom.h"
 #endif
 
@@ -163,11 +163,11 @@ bool StructTraits<
   }
 
   out->set_pages_per_sheet(data.pages_per_sheet());
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   DCHECK(out->advanced_settings().empty());
   if (!data.ReadAdvancedSettings(&out->advanced_settings()))
     return false;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(OS_CHROMEOS)
   out->set_send_user_info(data.send_user_info());
 
