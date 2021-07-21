--- Telegram/ThirdParty/tgcalls/tgcalls/Manager.cpp.orig	2021-07-21 01:10:26 UTC
+++ Telegram/ThirdParty/tgcalls/tgcalls/Manager.cpp
@@ -72,10 +72,6 @@ bool Manager::ResolvedNetworkStatus::operator==(const 
     return true;
 }
 
-bool Manager::ResolvedNetworkStatus::operator!=(const ResolvedNetworkStatus &rhs) {
-    return !(*this == rhs);
-}
-
 Manager::Manager(rtc::Thread *thread, Descriptor &&descriptor) :
 _thread(thread),
 _encryptionKey(descriptor.encryptionKey),
