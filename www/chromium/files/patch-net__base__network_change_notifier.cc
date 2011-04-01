--- ./net/base/network_change_notifier.cc.orig	2010-12-16 02:11:31.000000000 +0100
+++ ./net/base/network_change_notifier.cc	2010-12-20 20:15:08.000000000 +0100
@@ -42,7 +42,6 @@
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
