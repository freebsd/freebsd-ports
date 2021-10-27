--- headless/lib/browser/headless_web_contents_impl.cc.orig	2021-09-14 01:51:58 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -59,7 +59,7 @@ namespace headless {
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_WIN)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_WIN) || defined(OS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
