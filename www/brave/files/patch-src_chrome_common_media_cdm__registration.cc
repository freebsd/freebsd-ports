--- src/chrome/common/media/cdm_registration.cc.orig	2026-09-25 15:26:43 UTC
+++ src/chrome/common/media/cdm_registration.cc
@@ -33,7 +33,7 @@
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #include "components/cdm/common/cdm_manifest.h"
 #include "third_party/widevine/cdm/widevine_cdm_common.h"  // nogncheck
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/native_library.h"
 #include "chrome/common/chrome_paths.h"
 #include "chrome/common/media/component_widevine_cdm_hint_file_linux.h"
@@ -62,7 +62,7 @@
 #if BUILDFLAG(ENABLE_WIDEVINE)
 #if (BUILDFLAG(BUNDLE_WIDEVINE_CDM) ||            \
      BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // Create a CdmInfo for a Widevine CDM, using |version|, |cdm_library_path|, and
 // |capability|.
 std::unique_ptr<content::CdmInfo> CreateWidevineCdmInfo(
@@ -103,8 +103,13 @@
         // BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)) && (BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS))
 
-#if BUILDFLAG(BUNDLE_WIDEVINE_CDM) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+// On FreeBSD bundle_widevine_cdm stays false: turning it on would have the
+// build look for the CDM under third_party/widevine/cdm/freebsd/x64, which is
+// not in the tree and is not ours to ship.  www/foreign-cdm installs one at
+// run time instead, in the layout this function reads, so compile it here
+// regardless of the flag.  It returns nullptr when nothing is installed.
+#if (BUILDFLAG(BUNDLE_WIDEVINE_CDM) || BUILDFLAG(IS_BSD)) && \
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 // On Linux/ChromeOS we have to preload the CDM since it uses the zygote
 // sandbox. On Windows and Mac, CDM registration is handled by Component
 // Update (as the CDM can be loaded only when needed).
@@ -128,7 +133,7 @@
         // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 
 #if (BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT) && \
-     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)))
+     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)))
 // This code checks to see if Component Updater picked a version of the Widevine
 // CDM to be used last time it ran. (Component Updater may choose the bundled
 // CDM if there is not a new version available for download.) If there is one
@@ -170,7 +175,7 @@
       /*supports_sub_key_systems=*/false, kWidevineCdmDisplayName,
       kWidevineCdmType, base::FilePath());
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The Widevine CDM on Linux/ChromeOS needs to be registered (and loaded)
   // before the zygote is locked down. The CDM can be found from the version
   // bundled with Chrome (if BUNDLE_WIDEVINE_CDM = true) and/or the version
@@ -197,7 +202,7 @@
   // We should still use the version selected by Component Update (except for
   // case #3 above).
   std::unique_ptr<content::CdmInfo> bundled_widevine = nullptr;
-#if BUILDFLAG(BUNDLE_WIDEVINE_CDM)
+#if BUILDFLAG(BUNDLE_WIDEVINE_CDM) || BUILDFLAG(IS_BSD)
   bundled_widevine = GetBundledWidevine();
 #endif
 
@@ -434,7 +439,7 @@
 }
 
 #if BUILDFLAG(ENABLE_WIDEVINE) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 std::vector<content::CdmInfo> GetSoftwareSecureWidevine() {
   std::vector<content::CdmInfo> cdms;
   AddSoftwareSecureWidevine(&cdms);
