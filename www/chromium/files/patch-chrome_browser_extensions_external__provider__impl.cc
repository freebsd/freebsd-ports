--- chrome/browser/extensions/external_provider_impl.cc.orig	2016-05-11 19:02:14 UTC
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -645,7 +645,7 @@ void ExternalProviderImpl::CreateExterna
                                  Manifest::EXTERNAL_PREF_DOWNLOAD,
                                  oem_extension_creation_flags)));
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!profile->IsLegacySupervised()) {
     provider_list->push_back(
         linked_ptr<ExternalProviderInterface>(
@@ -687,7 +687,7 @@ void ExternalProviderImpl::CreateExterna
                 bundled_extension_creation_flags)));
 
     // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD))
     provider_list->push_back(
         linked_ptr<ExternalProviderInterface>(
             new ExternalProviderImpl(
