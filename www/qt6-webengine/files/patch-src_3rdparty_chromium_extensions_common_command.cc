--- src/3rdparty/chromium/extensions/common/command.cc.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/extensions/common/command.cc
@@ -286,7 +286,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif BUILDFLAG(IS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return values::kKeybindingPlatformLinux;
 #elif BUILDFLAG(IS_FUCHSIA)
   // TODO(crbug.com/40220501): Change this once we decide what string should be
