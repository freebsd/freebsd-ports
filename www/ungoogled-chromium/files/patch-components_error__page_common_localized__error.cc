--- components/error_page/common/localized_error.cc.orig	2025-10-21 16:57:35 UTC
+++ components/error_page/common/localized_error.cc
@@ -902,7 +902,7 @@ void AddSuggestionsDetails(int error_code,
   if (suggestions & SUGGEST_PROXY_CONFIG) {
     // Custom body string.
     std::u16string inner =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
         l10n_util::GetStringFUTF16(
             IDS_ERRORPAGES_SUGGESTION_PROXY_DISABLE_PLATFORM,
             l10n_util::GetStringUTF16(IDS_SETTINGS_TITLE),
