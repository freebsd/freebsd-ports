--- chrome/browser/enterprise/browser_management/browser_management_service.h.orig	2025-07-02 06:08:04 UTC
+++ chrome/browser/enterprise/browser_management/browser_management_service.h
@@ -41,7 +41,7 @@ class BrowserManagementService : public ManagementServ
 
   void TriggerPolicyStatusChangedForTesting() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetBrowserManagementIconForTesting(
       const gfx::Image& management_icon) override;
 #endif
@@ -50,7 +50,7 @@ class BrowserManagementService : public ManagementServ
   // PolicyStatusProvider::Observer:
   void OnPolicyStatusChanged() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Starts listening to changes to policies that affect the enterprise label
   // and pill.
   void StartListeningToPrefChanges(Profile* profile);
