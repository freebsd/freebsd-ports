--- net/base/network_change_notifier.cc.orig	2016-05-11 19:02:24 UTC
+++ net/base/network_change_notifier.cc
@@ -532,7 +532,6 @@ NetworkChangeNotifier* NetworkChangeNoti
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
