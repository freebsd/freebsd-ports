--- headless/lib/browser/headless_web_contents_impl.cc.orig	2026-03-15 18:32:51 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -74,7 +74,7 @@ BASE_FEATURE(kPrerender2InHeadlessMode, base::FEATURE_
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
