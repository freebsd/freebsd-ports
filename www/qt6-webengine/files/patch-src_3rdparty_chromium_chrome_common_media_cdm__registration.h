--- src/3rdparty/chromium/chrome/common/media/cdm_registration.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/common/media/cdm_registration.h
@@ -16,7 +16,7 @@ void RegisterCdmInfo(std::vector<content::CdmInfo>* cd
 void RegisterCdmInfo(std::vector<content::CdmInfo>* cdms);
 
 #if BUILDFLAG(ENABLE_WIDEVINE) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD))
 // Returns the software secure Widevine CDM, if one exists.
 std::vector<content::CdmInfo> GetSoftwareSecureWidevine();
 #endif
