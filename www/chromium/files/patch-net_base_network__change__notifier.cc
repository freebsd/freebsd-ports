--- net/base/network_change_notifier.cc.orig	2017-04-19 19:06:36 UTC
+++ net/base/network_change_notifier.cc
@@ -533,7 +533,6 @@ NetworkChangeNotifier* NetworkChangeNoti
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
