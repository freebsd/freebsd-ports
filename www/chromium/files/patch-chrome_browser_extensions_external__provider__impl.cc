--- chrome/browser/extensions/external_provider_impl.cc.orig	2018-03-20 23:05:17.000000000 +0100
+++ chrome/browser/extensions/external_provider_impl.cc	2018-03-24 13:22:20.011401000 +0100
@@ -689,7 +689,7 @@
         Manifest::EXTERNAL_PREF, Manifest::EXTERNAL_PREF_DOWNLOAD,
         oem_extension_creation_flags));
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!profile->IsLegacySupervised()) {
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
@@ -717,7 +717,7 @@
         bundled_extension_creation_flags));
 
     // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD))
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         new ExternalPrefLoader(chrome::DIR_USER_EXTERNAL_EXTENSIONS,
