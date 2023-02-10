--- src/3rdparty/chromium/printing/mojom/printing_context_mojom_traits.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/printing/mojom/printing_context_mojom_traits.h
@@ -168,7 +168,7 @@ struct StructTraits<printing::mojom::PrintSettingsData
     return s.pages_per_sheet();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const printing::PrintSettings::AdvancedSettings& advanced_settings(
       const printing::PrintSettings& s) {
     return s.advanced_settings();
