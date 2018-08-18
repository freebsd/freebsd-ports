--- third_party/crashpad/crashpad/util/misc/uuid.cc.orig	2018-07-19 19:46:52.081549000 +0200
+++ third_party/crashpad/crashpad/util/misc/uuid.cc	2018-07-19 19:47:05.207892000 +0200
@@ -95,7 +95,7 @@
   InitializeFromBytes(uuid);
   return true;
 #elif defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   // Linux, Android, and Fuchsia do not provide a UUID generator in a
   // widely-available system library. On Linux and Android, uuid_generate()
   // from libuuid is not available everywhere.
