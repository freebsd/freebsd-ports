--- ./net/base/network_change_notifier.cc.orig	2014-04-30 22:43:05.000000000 +0200
+++ ./net/base/network_change_notifier.cc	2014-05-04 14:38:48.000000000 +0200
@@ -470,7 +470,6 @@
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
