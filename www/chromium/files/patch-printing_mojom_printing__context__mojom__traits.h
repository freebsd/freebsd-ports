--- printing/mojom/printing_context_mojom_traits.h.orig	2021-12-16 15:15:50 UTC
+++ printing/mojom/printing_context_mojom_traits.h
@@ -171,12 +171,12 @@ struct StructTraits<printing::mojom::PrintSettingsData
     return s.pages_per_sheet();
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static const printing::PrintSettings::AdvancedSettings& advanced_settings(
       const printing::PrintSettings& s) {
     return s.advanced_settings();
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   static bool send_user_info(const printing::PrintSettings& s) {
