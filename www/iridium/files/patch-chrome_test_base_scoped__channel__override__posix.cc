--- chrome/test/base/scoped_channel_override_posix.cc.orig	2024-06-25 12:08:48 UTC
+++ chrome/test/base/scoped_channel_override_posix.cc
@@ -45,7 +45,7 @@ std::string GetVersionExtra(ScopedChannelOverride::Cha
       return "beta";
     case ScopedChannelOverride::Channel::kDev:
       return "unstable";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ScopedChannelOverride::Channel::kCanary:
       return "canary";
 #endif  // BUILDFLAG(IS_LINUX)
