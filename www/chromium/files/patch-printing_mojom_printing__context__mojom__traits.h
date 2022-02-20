--- printing/mojom/printing_context_mojom_traits.h.orig	2022-02-07 13:39:41 UTC
+++ printing/mojom/printing_context_mojom_traits.h
@@ -168,7 +168,7 @@ struct StructTraits<printing::mojom::PrintSettingsData
     return s.pages_per_sheet();
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static const printing::PrintSettings::AdvancedSettings& advanced_settings(
       const printing::PrintSettings& s) {
     return s.advanced_settings();
