--- chrome/common/media/cdm_registration.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/common/media/cdm_registration.cc
@@ -34,7 +34,7 @@
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #include "components/cdm/common/cdm_manifest.h"
 #include "third_party/widevine/cdm/widevine_cdm_common.h"  // nogncheck
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/native_library.h"
 #include "chrome/common/chrome_paths.h"
 #include "chrome/common/media/component_widevine_cdm_hint_file_linux.h"
@@ -59,7 +59,7 @@ using Robustness = content::CdmInfo::Robustness;
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #if (BUILDFLAG(BUNDLE_WIDEVINE_CDM) ||            \
      BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // Create a CdmInfo for a Widevine CDM, using |version|, |cdm_library_path|, and
 // |capability|.
 std::unique_ptr<content::CdmInfo> CreateWidevineCdmInfo(
@@ -101,7 +101,7 @@ std::unique_ptr<content::CdmInfo> CreateCdmInfoFromWid
         // BUILDFLAG(IS_CHROMEOS))
 
 #if BUILDFLAG(BUNDLE_WIDEVINE_CDM) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // On Linux/ChromeOS we have to preload the CDM since it uses the zygote
 // sandbox. On Windows and Mac, CDM registration is handled by Component
 // Update (as the CDM can be loaded only when needed).
@@ -125,7 +125,7 @@ std::unique_ptr<content::CdmInfo> GetBundledWidevine()
         // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 
 #if (BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT) && \
-     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)))
+     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)))
 // This code checks to see if Component Updater picked a version of the Widevine
 // CDM to be used last time it ran. (Component Updater may choose the bundled
 // CDM if there is not a new version available for download.) If there is one
@@ -167,7 +167,7 @@ void AddSoftwareSecureWidevine(std::vector<content::Cd
       /*supports_sub_key_systems=*/false, kWidevineCdmDisplayName,
       kWidevineCdmType, base::FilePath());
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The Widevine CDM on Linux/ChromeOS needs to be registered (and loaded)
   // before the zygote is locked down. The CDM can be found from the version
   // bundled with Chrome (if BUNDLE_WIDEVINE_CDM = true) and/or the version
@@ -434,7 +434,7 @@ void RegisterCdmInfo(std::vector<content::CdmInfo>* cd
 }
 
 #if BUILDFLAG(ENABLE_WIDEVINE) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 std::vector<content::CdmInfo> GetSoftwareSecureWidevine() {
   std::vector<content::CdmInfo> cdms;
   AddSoftwareSecureWidevine(&cdms);
