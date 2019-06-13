--- net/base/network_change_notifier.cc.orig	2019-06-04 18:55:26 UTC
+++ net/base/network_change_notifier.cc
@@ -215,7 +215,6 @@ NetworkChangeNotifier* NetworkChangeNotifier::Create()
 #elif defined(OS_FUCHSIA)
   return new NetworkChangeNotifierFuchsia(0 /* required_features */);
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
