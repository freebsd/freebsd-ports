--- src/chrome/browser/gcm/gcm_profile_service_factory.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/gcm/gcm_profile_service_factory.cc
@@ -109,7 +109,7 @@ GCMProfileServiceFactory::ScopedTestingF
 // static
 GCMProfileService* GCMProfileServiceFactory::GetForProfile(
     content::BrowserContext* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, incognito profiles are checked with IsIncognitoProfile().
   // It's possible for non-incognito profiles to also be off-the-record.
   bool is_profile_supported =
@@ -152,7 +152,7 @@ std::unique_ptr<KeyedService>
 GCMProfileServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* context) const {
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DCHECK(!profile->IsIncognitoProfile());
 #else
   DCHECK(!profile->IsOffTheRecord());
