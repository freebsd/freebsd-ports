--- ./net/base/network_change_notifier.cc.orig	2014-08-20 21:02:28.000000000 +0200
+++ ./net/base/network_change_notifier.cc	2014-08-22 15:06:26.000000000 +0200
@@ -521,7 +521,6 @@
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
