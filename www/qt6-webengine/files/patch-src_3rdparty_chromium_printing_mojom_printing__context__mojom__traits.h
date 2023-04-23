--- src/3rdparty/chromium/printing/mojom/printing_context_mojom_traits.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/printing/mojom/printing_context_mojom_traits.h
@@ -158,7 +158,7 @@ struct StructTraits<printing::mojom::PrintSettingsData
     return s.pages_per_sheet();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const printing::PrintSettings::AdvancedSettings& advanced_settings(
       const printing::PrintSettings& s) {
     return s.advanced_settings();
