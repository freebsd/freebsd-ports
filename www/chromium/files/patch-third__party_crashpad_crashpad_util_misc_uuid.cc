--- third_party/crashpad/crashpad/util/misc/uuid.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/crashpad/crashpad/util/misc/uuid.cc
@@ -100,7 +100,7 @@ bool UUID::InitializeWithNew() {
   InitializeFromBytes(uuid);
   return true;
 #elif defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // Linux, Android, and Fuchsia do not provide a UUID generator in a
   // widely-available system library. On Linux and Android, uuid_generate()
   // from libuuid is not available everywhere.
