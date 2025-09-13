--- remoting/host/policy_watcher.cc.orig	2025-09-11 13:19:19 UTC
+++ remoting/host/policy_watcher.cc
@@ -183,7 +183,7 @@ base::Value::Dict PolicyWatcher::GetDefaultPolicies() 
   result.Set(key::kRemoteAccessHostAllowEnterpriseFileTransfer, false);
   result.Set(key::kClassManagementEnabled, "disabled");
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result.Set(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
