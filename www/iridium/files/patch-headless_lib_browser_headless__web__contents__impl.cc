--- headless/lib/browser/headless_web_contents_impl.cc.orig	2025-05-07 06:48:23 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -70,7 +70,7 @@ BASE_FEATURE(kPrerender2InHeadlessMode,
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
