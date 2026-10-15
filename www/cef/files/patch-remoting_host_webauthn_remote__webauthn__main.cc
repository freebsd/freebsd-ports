--- remoting/host/webauthn/remote_webauthn_main.cc.orig	2026-07-01 06:24:19 UTC
+++ remoting/host/webauthn/remote_webauthn_main.cc
@@ -26,7 +26,7 @@
 #include "remoting/host/webauthn/remote_webauthn_caller_security_utils.h"
 #include "remoting/host/webauthn/remote_webauthn_native_messaging_host.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -49,7 +49,7 @@ int RemoteWebAuthnMain(int argc, char** argv) {
 
 #if defined(REMOTING_ENABLE_CRASH_REPORTING)
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
