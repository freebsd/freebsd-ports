--- chrome/browser/extensions/external_provider_impl.cc.orig	2019-10-21 19:06:22 UTC
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -765,7 +765,7 @@ void ExternalProviderImpl::CreateExternalProviders(
     chromeos::DemoSession::Get()->SetExtensionsExternalLoader(loader);
     provider_list->push_back(std::move(demo_apps_provider));
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   provider_list->push_back(std::make_unique<ExternalProviderImpl>(
       service,
       base::MakeRefCounted<ExternalPrefLoader>(
@@ -793,7 +793,7 @@ void ExternalProviderImpl::CreateExternalProviders(
         bundled_extension_creation_flags));
 
     // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && BUILDFLAG(CHROMIUM_BRANDING))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(CHROMIUM_BRANDING))
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         base::MakeRefCounted<ExternalPrefLoader>(
