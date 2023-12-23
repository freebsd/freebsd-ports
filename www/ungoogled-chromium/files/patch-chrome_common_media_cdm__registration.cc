--- chrome/common/media/cdm_registration.cc.orig	2023-12-23 12:33:28 UTC
+++ chrome/common/media/cdm_registration.cc
@@ -26,11 +26,11 @@
 
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #include "third_party/widevine/cdm/widevine_cdm_common.h"  // nogncheck
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "base/native_library.h"
 #include "chrome/common/chrome_paths.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/no_destructor.h"
 #include "chrome/common/media/component_widevine_cdm_hint_file_linux.h"
 #include "media/cdm/supported_audio_codecs.h"
@@ -56,7 +56,7 @@ using Robustness = content::CdmInfo::Robustness;
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
 // sandbox. On Windows and Mac, the bundled CDM is handled by the component
 // updater.
@@ -125,7 +125,7 @@ content::CdmInfo* GetBundledWidevine() {
         // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 
 #if BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // This code checks to see if a component updated Widevine CDM can be found. If
 // there is one and it looks valid, return the CdmInfo for that CDM. Otherwise
 // return nullptr.
@@ -160,7 +160,7 @@ void AddSoftwareSecureWidevine(std::vector<content::Cd
       /*supports_sub_key_systems=*/false, kWidevineCdmDisplayName,
       kWidevineCdmType, base::Version(), base::FilePath());
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(WIDEVINE_CDM_MIN_GLIBC_VERSION)
   base::Version glibc_version(gnu_get_libc_version());
   DCHECK(glibc_version.IsValid());
