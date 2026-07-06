--- chrome/browser/enterprise/browser_management/browser_management_service.h.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/enterprise/browser_management/browser_management_service.h
@@ -17,7 +17,7 @@
 #include "components/prefs/pref_change_registrar.h"
 #include "ui/base/models/image_model.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/status_provider/user_cloud_policy_status_provider.h"  // nogncheck crbug.com/40147906
 #endif
 
@@ -45,7 +45,7 @@ class BrowserManagementService : public ManagementServ
 
   void TriggerPolicyStatusChangedForTesting() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetBrowserManagementIconForTesting(
       const gfx::Image& management_icon) override;
 #endif
@@ -54,7 +54,7 @@ class BrowserManagementService : public ManagementServ
   // PolicyStatusProvider::Observer:
   void OnPolicyStatusChanged() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Starts listening to changes to policies that affect the enterprise label
   // and pill.
   void StartListeningToPrefChanges(Profile* profile);
