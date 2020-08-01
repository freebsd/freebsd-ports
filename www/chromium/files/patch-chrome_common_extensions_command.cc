--- chrome/common/extensions/command.cc.orig	2020-07-07 21:57:33 UTC
+++ chrome/common/extensions/command.cc
@@ -293,7 +293,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif defined(OS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
