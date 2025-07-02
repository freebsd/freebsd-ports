--- remoting/host/setup/me2me_native_messaging_host_main.cc.orig	2025-07-02 06:08:04 UTC
+++ remoting/host/setup/me2me_native_messaging_host_main.cc
@@ -41,7 +41,7 @@
 #include "base/apple/scoped_nsautorelease_pool.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -99,7 +99,7 @@ int Me2MeNativeMessagingHostMain(int argc, char** argv
   // needs to be initialized first, so that the preference for crash-reporting
   // can be looked up in the config file.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
