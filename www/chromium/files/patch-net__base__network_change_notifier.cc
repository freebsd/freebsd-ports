--- ./net/base/network_change_notifier.cc.orig	2014-08-12 21:02:39.000000000 +0200
+++ ./net/base/network_change_notifier.cc	2014-08-13 09:56:57.000000000 +0200
@@ -508,7 +508,6 @@
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
