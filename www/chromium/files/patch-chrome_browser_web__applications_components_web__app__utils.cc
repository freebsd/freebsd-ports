--- chrome/browser/web_applications/components/web_app_utils.cc.orig	2021-07-28 07:46:50 UTC
+++ chrome/browser/web_applications/components/web_app_utils.cc
@@ -198,13 +198,13 @@ std::u16string GetFileTypeAssociationsHandledByWebApps
   const apps::FileHandlers file_handlers =
       GetFileHandlersForAllWebAppsWithOrigin(profile, url);
   std::vector<std::string> associations;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::set<std::string> mime_types_set =
       apps::GetMimeTypesFromFileHandlers(file_handlers);
   associations.reserve(mime_types_set.size());
   associations.insert(associations.end(), mime_types_set.begin(),
                       mime_types_set.end());
-#else   // !defined(OS_LINUX)
+#else   // !defined(OS_LINUX) || defined(OS_BSD)
   std::set<std::string> extensions_set =
       apps::GetFileExtensionsFromFileHandlers(file_handlers);
   associations.reserve(extensions_set.size());
@@ -215,7 +215,7 @@ std::u16string GetFileTypeAssociationsHandledByWebApps
                  [](const std::string& extension) {
                    return base::ToUpperASCII(extension.substr(1));
                  });
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   return base::UTF8ToUTF16(base::JoinString(
       associations, l10n_util::GetStringUTF8(
