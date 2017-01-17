--- chrome/browser/extensions/external_provider_impl.cc.orig	2016-12-01 23:02:07 UTC
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -638,7 +638,7 @@ void ExternalProviderImpl::CreateExterna
         Manifest::EXTERNAL_PREF, Manifest::EXTERNAL_PREF_DOWNLOAD,
         oem_extension_creation_flags));
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!profile->IsLegacySupervised()) {
     provider_list->push_back(base::MakeUnique<ExternalProviderImpl>(
         service,
@@ -664,7 +664,7 @@ void ExternalProviderImpl::CreateExterna
         bundled_extension_creation_flags));
 
     // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD))
     provider_list->push_back(base::MakeUnique<ExternalProviderImpl>(
         service, new ExternalPrefLoader(chrome::DIR_USER_EXTERNAL_EXTENSIONS,
                                         ExternalPrefLoader::NONE, nullptr),
