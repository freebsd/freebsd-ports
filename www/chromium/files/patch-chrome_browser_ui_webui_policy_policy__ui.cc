--- chrome/browser/ui/webui/policy/policy_ui.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/ui/webui/policy/policy_ui.cc
@@ -149,7 +149,7 @@ void CreateAndAddPolicyUIHtmlSource(Profile* profile) 
       {"statusFlexOrgNoPolicy", IDS_POLICY_STATUS_FLEX_ORG_NO_POLICY},
       {"statusDevice", IDS_POLICY_STATUS_DEVICE},
       {"statusMachine", IDS_POLICY_STATUS_MACHINE},
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"statusUpdater", IDS_POLICY_STATUS_UPDATER},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
       {"statusUser", IDS_POLICY_STATUS_USER},
