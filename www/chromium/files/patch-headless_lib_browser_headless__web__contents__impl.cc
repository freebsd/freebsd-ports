--- headless/lib/browser/headless_web_contents_impl.cc.orig	2025-12-05 10:12:50 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -71,7 +71,7 @@ BASE_FEATURE(kPrerender2InHeadlessMode, base::FEATURE_
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
