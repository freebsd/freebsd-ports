--- remoting/host/policy_watcher.cc.orig	2022-08-31 12:19:35 UTC
+++ remoting/host/policy_watcher.cc
@@ -177,7 +177,7 @@ std::unique_ptr<base::DictionaryValue> PolicyWatcher::
   auto result = std::make_unique<base::DictionaryValue>();
   result->SetBoolKey(key::kRemoteAccessHostFirewallTraversal, true);
   result->SetBoolKey(key::kRemoteAccessHostRequireCurtain, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result->SetBoolKey(key::kRemoteAccessHostMatchUsername, false);
 #endif
   result->Set(key::kRemoteAccessHostClientDomainList,
