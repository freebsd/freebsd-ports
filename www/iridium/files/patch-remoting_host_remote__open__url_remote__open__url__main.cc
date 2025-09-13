--- remoting/host/remote_open_url/remote_open_url_main.cc.orig	2025-09-11 13:19:19 UTC
+++ remoting/host/remote_open_url/remote_open_url_main.cc
@@ -27,7 +27,7 @@
 #include "remoting/host/usage_stats_consent.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -51,7 +51,7 @@ int RemoteOpenUrlMain(int argc, char** argv) {
 
 #if defined(REMOTING_ENABLE_CRASH_REPORTING)
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
