--- src/3rdparty/chromium/third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc.orig	2022-03-25 21:59:56 UTC
+++ src/3rdparty/chromium/third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc
@@ -64,7 +64,7 @@ bool StructTraits<blink::mojom::RendererPreferencesDat
   if (!data.ReadAcceptLanguages(&out->accept_languages))
     return false;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadSystemFontFamilyName(&out->system_font_family_name))
     return false;
 #endif
