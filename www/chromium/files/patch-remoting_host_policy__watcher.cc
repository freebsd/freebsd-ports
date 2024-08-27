--- remoting/host/policy_watcher.cc.orig	2024-08-26 12:06:38 UTC
+++ remoting/host/policy_watcher.cc
@@ -178,7 +178,7 @@ base::Value::Dict PolicyWatcher::GetDefaultPolicies() 
              true);
   result.Set(key::kRemoteAccessHostAllowEnterpriseFileTransfer, false);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result.Set(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
