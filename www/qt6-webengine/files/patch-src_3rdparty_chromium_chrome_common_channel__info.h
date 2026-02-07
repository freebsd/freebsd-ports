--- src/3rdparty/chromium/chrome/common/channel_info.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/common/channel_info.h
@@ -12,7 +12,7 @@
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace base {
 class Environment;
 }
@@ -100,7 +100,7 @@ std::string GetChannelSuffixForDataDir();
 std::string GetChannelSuffixForDataDir();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetChannelSuffixForExtraFlagsEnvVarName();
 
 // Returns the channel-specific filename of the desktop shortcut used to launch
