--- chrome/browser/enterprise/browser_management/browser_management_service.h.orig	2025-06-19 07:37:57 UTC
+++ chrome/browser/enterprise/browser_management/browser_management_service.h
@@ -44,7 +44,7 @@ class BrowserManagementService : public ManagementServ
   // PolicyStatusProvider::Observer:
   void OnPolicyStatusChanged() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Starts listening to changes to policies that affect the enterprise label
   // and pill.
   void StartListeningToPrefChanges(Profile* profile);
