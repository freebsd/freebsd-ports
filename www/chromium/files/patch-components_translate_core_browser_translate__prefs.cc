--- components/translate/core/browser/translate_prefs.cc.orig	2022-02-28 16:54:41 UTC
+++ components/translate/core/browser/translate_prefs.cc
@@ -905,7 +905,7 @@ bool TranslatePrefs::CanTranslateLanguage(
 bool TranslatePrefs::IsDetailedLanguageSettingsEnabled() {
 #if BUILDFLAG(IS_ANDROID)
   return base::FeatureList::IsEnabled(language::kDetailedLanguageSettings);
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       language::kDesktopDetailedLanguageSettings);
 #else
