--- chrome/common/extensions/command.cc.orig	2016-05-11 19:02:17 UTC
+++ chrome/common/extensions/command.cc
@@ -306,7 +306,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif defined(OS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
