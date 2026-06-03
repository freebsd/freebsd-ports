--- chrome/browser/regional_capabilities/regional_capabilities_service_factory.h.orig	2026-04-15 12:07:04 UTC
+++ chrome/browser/regional_capabilities/regional_capabilities_service_factory.h
@@ -31,7 +31,7 @@ class RegionalCapabilitiesServiceFactory : public Prof
 
   static RegionalCapabilitiesServiceFactory* GetInstance();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the system profile is in a region where we can show a
   // search engine choice screen. If the profile is not a system profile, this
   // function crashes. Used for clients associated with system profiles (where
