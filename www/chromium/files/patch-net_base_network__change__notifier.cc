--- net/base/network_change_notifier.cc.orig	2017-06-05 19:03:09 UTC
+++ net/base/network_change_notifier.cc
@@ -533,7 +533,6 @@ NetworkChangeNotifier* NetworkChangeNotifier::Create()
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
