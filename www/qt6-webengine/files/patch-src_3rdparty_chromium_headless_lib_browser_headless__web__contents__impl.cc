--- src/3rdparty/chromium/headless/lib/browser/headless_web_contents_impl.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/headless/lib/browser/headless_web_contents_impl.cc
@@ -61,7 +61,7 @@ namespace headless {
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
