--- remoting/host/policy_watcher.cc.orig	2026-09-25 15:26:43 UTC
+++ remoting/host/policy_watcher.cc
@@ -182,7 +182,7 @@ base::DictValue PolicyWatcher::GetDefaultPolicies() {
   result.Set(key::kRemoteAccessHostAllowEnterpriseFileTransfer, false);
   result.Set(key::kClassManagementEnabled, "disabled");
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result.Set(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
