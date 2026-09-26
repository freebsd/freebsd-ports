--- third_party/openscreen/src/cast/common/channel/message_util.cc.orig	2026-09-25 15:26:43 UTC
+++ third_party/openscreen/src/cast/common/channel/message_util.cc
@@ -59,7 +59,7 @@ constexpr VirtualConnectPlatformValue GetVirtualConnec
   return kMacOSX;
 #elif BUILDFLAG(IS_CHROMEOS)
   return kChromeOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kLinux;
 #else
   return kOtherPlatform;
