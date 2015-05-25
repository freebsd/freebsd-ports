--- chrome/common/extensions/command.cc.orig	2015-04-14 18:18:50.000000000 -0400
+++ chrome/common/extensions/command.cc	2015-04-28 09:31:06.624015000 -0400
@@ -301,7 +301,7 @@
   return values::kKeybindingPlatformMac;
 #elif defined(OS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
