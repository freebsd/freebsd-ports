--- chrome/common/media/cdm_registration.h.orig	2024-05-21 18:07:39 UTC
+++ chrome/common/media/cdm_registration.h
@@ -14,7 +14,7 @@
 // Register CdmInfo for Content Decryption Modules (CDM) supported.
 void RegisterCdmInfo(std::vector<content::CdmInfo>* cdms);
 
-#if BUILDFLAG(ENABLE_WIDEVINE) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_WIDEVINE) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 // Returns the software secure Widevine CDM.
 std::vector<content::CdmInfo> GetSoftwareSecureWidevineForTesting();
 #endif
