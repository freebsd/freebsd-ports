--- chrome/common/media/cdm_registration.cc.orig	2024-07-30 11:12:21 UTC
+++ chrome/common/media/cdm_registration.cc
@@ -33,7 +33,7 @@
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #include "components/cdm/common/cdm_manifest.h"
 #include "third_party/widevine/cdm/widevine_cdm_common.h"  // nogncheck
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/native_library.h"
 #include "chrome/common/chrome_paths.h"
 #include "chrome/common/media/component_widevine_cdm_hint_file_linux.h"
@@ -86,7 +86,7 @@ void ReportLacrosUMA(LacrosBundledWidevine value) {
 
 #if (BUILDFLAG(BUNDLE_WIDEVINE_CDM) ||            \
      BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // Create a CdmInfo for a Widevine CDM, using |version|, |cdm_library_path|, and
 // |capability|.
 std::unique_ptr<content::CdmInfo> CreateWidevineCdmInfo(
@@ -131,7 +131,7 @@ std::unique_ptr<content::CdmInfo> CreateCdmInfoFromWid
         // BUILDFLAG(IS_CHROMEOS))
 
 #if BUILDFLAG(BUNDLE_WIDEVINE_CDM) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // On Linux/ChromeOS we have to preload the CDM since it uses the zygote
 // sandbox. On Windows and Mac, CDM registration is handled by Component
 // Update (as the CDM can be loaded only when needed).
@@ -185,7 +185,7 @@ std::unique_ptr<content::CdmInfo> GetAshBundledWidevin
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #if (BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT) &&             \
-     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH))) || \
+     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD))) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
 // This code checks to see if Component Updater picked a version of the Widevine
 // CDM to be used last time it ran. (Component Updater may choose the bundled
@@ -232,7 +232,7 @@ void AddSoftwareSecureWidevine(std::vector<content::Cd
       /*supports_sub_key_systems=*/false, kWidevineCdmDisplayName,
       kWidevineCdmType, base::Version(), base::FilePath());
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(WIDEVINE_CDM_MIN_GLIBC_VERSION)
   base::Version glibc_version(gnu_get_libc_version());
   DCHECK(glibc_version.IsValid());
@@ -493,7 +493,7 @@ void RegisterCdmInfo(std::vector<content::CdmInfo>* cd
 }
 
 #if BUILDFLAG(ENABLE_WIDEVINE) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD))
 std::vector<content::CdmInfo> GetSoftwareSecureWidevine() {
   std::vector<content::CdmInfo> cdms;
   AddSoftwareSecureWidevine(&cdms);
