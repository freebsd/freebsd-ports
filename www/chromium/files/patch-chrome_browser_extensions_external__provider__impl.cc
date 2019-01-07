--- chrome/browser/extensions/external_provider_impl.cc.orig	2018-11-19 19:55:03.000000000 +0100
+++ chrome/browser/extensions/external_provider_impl.cc	2018-12-04 15:09:57.567637000 +0100
@@ -711,7 +711,7 @@
     provider_list->push_back(std::move(demo_apps_provider));
   }
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!profile->IsLegacySupervised()) {
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
@@ -739,7 +739,7 @@
         bundled_extension_creation_flags));
 
     // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD))
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         new ExternalPrefLoader(chrome::DIR_USER_EXTERNAL_EXTENSIONS,
