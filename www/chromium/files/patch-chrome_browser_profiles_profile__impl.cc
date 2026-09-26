--- chrome/browser/profiles/profile_impl.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/profiles/profile_impl.cc
@@ -271,7 +271,7 @@
 #include "chrome/browser/safe_browsing/safe_browsing_service.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/gapis/gapis_service_factory.h"
 #include "components/gapis/gapis_service.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
@@ -280,6 +280,10 @@
 #include "chrome/browser/themes/theme_service_factory.h"
 #endif  // !BUILDFLAG(IS_ANDROID)
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 using bookmarks::BookmarkModel;
 using content::BrowserThread;
 using content::DownloadManagerDelegate;
@@ -643,7 +647,7 @@ void ProfileImpl::LoadPrefsForNormalStartup(bool async
   policy_provider = GetUserCloudPolicyManagerAsh();
 #else  // !BUILDFLAG(IS_CHROMEOS)
   {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (GetTestingCloudPolicyManagerFactory()) {
       auto result = GetTestingCloudPolicyManagerFactory().Run(this);
       if (std::holds_alternative<
@@ -662,7 +666,7 @@ void ProfileImpl::LoadPrefsForNormalStartup(bool async
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
     if (!cloud_policy_manager) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       ProfileAttributesEntry* entry = nullptr;
       if (g_browser_process->profile_manager()) {
         entry = g_browser_process->profile_manager()
@@ -855,7 +859,7 @@ void ProfileImpl::DoFinalInit(CreateMode create_mode) 
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Bootstrap and initialize the Gapis service.
   if (gapis::GapisService* gapis_service =
           GapisServiceFactory::GetForProfile(this)) {
@@ -951,7 +955,17 @@ void ProfileImpl::DoFinalInit(CreateMode create_mode) 
 }
 
 base::FilePath ProfileImpl::last_selected_directory() {
+#if BUILDFLAG(IS_OPENBSD)
+  // If unveil(2) is used, force the file dialog directory to something we
+  // know is available.
+  auto* sandbox = sandbox::policy::SandboxLinux::GetInstance();
+  if (sandbox->unveil_initialized())
+    return GetPrefs()->GetFilePath(prefs::kDownloadDefaultDirectory);
+  else
+    return GetPrefs()->GetFilePath(prefs::kSelectFileLastDirectory);
+#else
   return GetPrefs()->GetFilePath(prefs::kSelectFileLastDirectory);
+#endif
 }
 
 void ProfileImpl::set_last_selected_directory(const base::FilePath& path) {
