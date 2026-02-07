--- src/3rdparty/chromium/chrome/browser/gcm/gcm_profile_service_factory.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/browser/gcm/gcm_profile_service_factory.cc
@@ -91,7 +91,7 @@ GCMProfileService* GCMProfileServiceFactory::GetForPro
 // static
 GCMProfileService* GCMProfileServiceFactory::GetForProfile(
     content::BrowserContext* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, incognito profiles are checked with IsIncognitoProfile().
   // It's possible for non-incognito profiles to also be off-the-record.
   bool is_profile_supported =
@@ -134,7 +134,7 @@ GCMProfileServiceFactory::BuildServiceInstanceForBrows
 GCMProfileServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* context) const {
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DCHECK(!profile->IsIncognitoProfile());
 #else
   DCHECK(!profile->IsOffTheRecord());
