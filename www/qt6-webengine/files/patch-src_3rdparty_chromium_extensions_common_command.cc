--- src/3rdparty/chromium/extensions/common/command.cc.orig	2023-10-11 18:22:24 UTC
+++ src/3rdparty/chromium/extensions/common/command.cc
@@ -282,7 +282,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif BUILDFLAG(IS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return values::kKeybindingPlatformLinux;
 #elif BUILDFLAG(IS_FUCHSIA)
   // TODO(crbug.com/1312215): Change this once we decide what string should be
