--- net/base/network_change_notifier.cc.orig	2019-07-24 18:58:32 UTC
+++ net/base/network_change_notifier.cc
@@ -225,7 +225,6 @@ NetworkChangeNotifier* NetworkChangeNotifier::Create()
 #elif defined(OS_FUCHSIA)
   return new NetworkChangeNotifierFuchsia(0 /* required_features */);
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
