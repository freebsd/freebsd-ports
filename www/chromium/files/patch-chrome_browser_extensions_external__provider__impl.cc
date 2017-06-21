--- chrome/browser/extensions/external_provider_impl.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -655,7 +655,7 @@ void ExternalProviderImpl::CreateExternalProviders(
         Manifest::EXTERNAL_PREF, Manifest::EXTERNAL_PREF_DOWNLOAD,
         oem_extension_creation_flags));
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!profile->IsLegacySupervised()) {
     provider_list->push_back(base::MakeUnique<ExternalProviderImpl>(
         service,
@@ -681,7 +681,7 @@ void ExternalProviderImpl::CreateExternalProviders(
         bundled_extension_creation_flags));
 
     // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD))
     provider_list->push_back(base::MakeUnique<ExternalProviderImpl>(
         service, new ExternalPrefLoader(chrome::DIR_USER_EXTERNAL_EXTENSIONS,
                                         ExternalPrefLoader::NONE, nullptr),
