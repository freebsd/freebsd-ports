--- chrome/test/base/scoped_channel_override_posix.cc.orig	2026-01-14 08:33:23 UTC
+++ chrome/test/base/scoped_channel_override_posix.cc
@@ -22,7 +22,7 @@ version_info::Channel GetBaseChannel(ScopedChannelOver
       return version_info::Channel::BETA;
     case ScopedChannelOverride::Channel::kDev:
       return version_info::Channel::DEV;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ScopedChannelOverride::Channel::kCanary:
       return version_info::Channel::CANARY;
 #endif  // BUILDFLAG(IS_LINUX)
