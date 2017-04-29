--- chrome/common/extensions/command.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/common/extensions/command.cc
@@ -302,7 +302,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif defined(OS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
