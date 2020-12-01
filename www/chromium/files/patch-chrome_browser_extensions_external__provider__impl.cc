--- chrome/browser/extensions/external_provider_impl.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -776,7 +776,7 @@ void ExternalProviderImpl::CreateExternalProviders(
   }
 #endif
   if (!profile->GetPrefs()->GetBoolean(pref_names::kBlockExternalExtensions)) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         base::MakeRefCounted<ExternalPrefLoader>(
@@ -803,7 +803,7 @@ void ExternalProviderImpl::CreateExternalProviders(
           bundled_extension_creation_flags));
 
       // Define a per-user source of external extensions.
-#if defined(OS_MAC) || ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && \
+#if defined(OS_MAC) || defined(OS_BSD) || ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && \
                         BUILDFLAG(CHROMIUM_BRANDING))
       provider_list->push_back(std::make_unique<ExternalProviderImpl>(
           service,
