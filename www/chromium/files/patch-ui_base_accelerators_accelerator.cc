--- ui/base/accelerators/accelerator.cc.orig	2026-07-01 06:24:19 UTC
+++ ui/base/accelerators/accelerator.cc
@@ -402,7 +402,7 @@ std::vector<std::u16string> Accelerator::GetLongFormMo
     modifiers.push_back(l10n_util::GetStringUTF16(IDS_APP_SEARCH_KEY));
 #elif BUILDFLAG(IS_WIN)
     modifiers.push_back(l10n_util::GetStringUTF16(IDS_APP_WINDOWS_KEY));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     modifiers.push_back(l10n_util::GetStringUTF16(IDS_APP_SUPER_KEY));
 #else
     NOTREACHED();
