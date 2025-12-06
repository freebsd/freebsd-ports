--- components/error_page/common/localized_error.cc.orig	2025-12-05 10:12:50 UTC
+++ components/error_page/common/localized_error.cc
@@ -896,7 +896,7 @@ void AddSuggestionsDetails(int error_code,
   if (suggestions & SUGGEST_PROXY_CONFIG) {
     // Custom body string.
     std::u16string inner =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
         l10n_util::GetStringFUTF16(
             IDS_ERRORPAGES_SUGGESTION_PROXY_DISABLE_PLATFORM,
             l10n_util::GetStringUTF16(IDS_SETTINGS_TITLE),
