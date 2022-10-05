--- remoting/host/policy_watcher.cc.orig	2022-10-05 07:34:01 UTC
+++ remoting/host/policy_watcher.cc
@@ -184,7 +184,7 @@ std::unique_ptr<base::DictionaryValue> PolicyWatcher::
   result->SetStringKey(key::kRemoteAccessHostUdpPortRange, "");
   result->SetIntKey(key::kRemoteAccessHostClipboardSizeBytes, -1);
   result->SetBoolKey(key::kRemoteAccessHostAllowRemoteSupportConnections, true);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result->SetBoolKey(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
