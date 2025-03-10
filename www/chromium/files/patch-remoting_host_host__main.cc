--- remoting/host/host_main.cc.orig	2025-03-05 08:14:56 UTC
+++ remoting/host/host_main.cc
@@ -55,7 +55,7 @@ int FileChooserMain();
 int RdpDesktopSessionMain();
 int UrlForwarderConfiguratorMain();
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 int XSessionChooserMain();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -68,7 +68,7 @@ const char kUsageMessage[] =
     "\n"
     "Options:\n"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
     "Linux.\n"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -161,7 +161,7 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
   } else if (process_type == kProcessTypeUrlForwarderConfigurator) {
     main_routine = &UrlForwarderConfiguratorMain;
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -229,7 +229,7 @@ int HostMain(int argc, char** argv) {
   // Note that we enable crash reporting only if the user has opted in to having
   // the crash reports uploaded.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashReporting();
 #elif BUILDFLAG(IS_WIN)
     // TODO: joedow - Enable crash reporting for the RDP process.
