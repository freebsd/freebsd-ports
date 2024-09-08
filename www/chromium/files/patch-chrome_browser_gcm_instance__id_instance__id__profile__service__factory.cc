--- chrome/browser/gcm/instance_id/instance_id_profile_service_factory.cc.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/gcm/instance_id/instance_id_profile_service_factory.cc
@@ -16,7 +16,7 @@ namespace instance_id {
 // static
 InstanceIDProfileService* InstanceIDProfileServiceFactory::GetForProfile(
     content::BrowserContext* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, the guest profile is actually the primary OTR profile of
   // the "regular" guest profile.  The regular guest profile is never used
   // directly by users.  Also, user are not able to create child OTR profiles
@@ -64,7 +64,7 @@ InstanceIDProfileServiceFactory::~InstanceIDProfileSer
 KeyedService* InstanceIDProfileServiceFactory::BuildServiceInstanceFor(
     content::BrowserContext* context) const {
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, incognito profiles are checked with IsIncognitoProfile().
   // It's possible for non-incognito profiles to also be off-the-record.
   bool is_incognito = profile->IsIncognitoProfile();
