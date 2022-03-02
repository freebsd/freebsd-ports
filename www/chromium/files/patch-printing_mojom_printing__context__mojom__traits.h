--- printing/mojom/printing_context_mojom_traits.h.orig	2022-02-28 16:54:41 UTC
+++ printing/mojom/printing_context_mojom_traits.h
@@ -168,7 +168,7 @@ struct StructTraits<printing::mojom::PrintSettingsData
     return s.pages_per_sheet();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const printing::PrintSettings::AdvancedSettings& advanced_settings(
       const printing::PrintSettings& s) {
     return s.advanced_settings();
