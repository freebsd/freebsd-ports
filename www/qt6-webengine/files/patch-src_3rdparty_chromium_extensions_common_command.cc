--- src/3rdparty/chromium/extensions/common/command.cc.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/extensions/common/command.cc
@@ -280,7 +280,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif BUILDFLAG(IS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return values::kKeybindingPlatformLinux;
 #elif BUILDFLAG(IS_FUCHSIA)
   // TODO(crbug.com/1312215): Change this once we decide what string should be
