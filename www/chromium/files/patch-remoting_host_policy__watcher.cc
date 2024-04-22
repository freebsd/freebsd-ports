--- remoting/host/policy_watcher.cc.orig	2024-03-22 08:19:40 UTC
+++ remoting/host/policy_watcher.cc
@@ -192,7 +192,7 @@ base::Value::Dict PolicyWatcher::GetDefaultPolicies() 
              true);
   result.Set(key::kRemoteAccessHostAllowEnterpriseFileTransfer, false);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result.Set(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
