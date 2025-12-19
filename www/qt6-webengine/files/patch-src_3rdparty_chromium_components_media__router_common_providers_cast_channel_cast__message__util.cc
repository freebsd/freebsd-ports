--- src/3rdparty/chromium/components/media_router/common/providers/cast/channel/cast_message_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/media_router/common/providers/cast/channel/cast_message_util.cc
@@ -168,7 +168,7 @@ int GetVirtualConnectPlatformValue() {
   return 4;
 #elif BUILDFLAG(IS_CHROMEOS)
   return 5;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return 6;
 #else
   return 0;
