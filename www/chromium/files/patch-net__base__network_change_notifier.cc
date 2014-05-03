--- ./net/base/network_change_notifier.cc.orig	2014-04-24 22:35:53.000000000 +0200
+++ ./net/base/network_change_notifier.cc	2014-04-24 23:23:46.000000000 +0200
@@ -470,7 +470,6 @@
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
