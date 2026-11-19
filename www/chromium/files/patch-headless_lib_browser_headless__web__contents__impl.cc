--- headless/lib/browser/headless_web_contents_impl.cc.orig	2026-11-19 12:25:27 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -75,7 +75,7 @@ BASE_FEATURE(kPrerender2InHeadlessMode, base::FEATURE_
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
