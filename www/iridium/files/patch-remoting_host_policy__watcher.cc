--- remoting/host/policy_watcher.cc.orig	2025-05-07 06:48:23 UTC
+++ remoting/host/policy_watcher.cc
@@ -177,7 +177,7 @@ base::Value::Dict PolicyWatcher::GetDefaultPolicies() 
              true);
   result.Set(key::kRemoteAccessHostAllowEnterpriseFileTransfer, false);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result.Set(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
