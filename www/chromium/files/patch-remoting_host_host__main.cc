--- remoting/host/host_main.cc.orig	2022-02-07 13:39:41 UTC
+++ remoting/host/host_main.cc
@@ -50,7 +50,7 @@ int FileChooserMain();
 int RdpDesktopSessionMain();
 int UrlForwarderConfiguratorMain();
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 int XSessionChooserMain();
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
@@ -63,7 +63,7 @@ const char kUsageMessage[] =
     "\n"
     "Options:\n"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
     "Linux.\n"
 #endif  // defined(OS_LINUX)
@@ -152,7 +152,7 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
   } else if (process_type == kProcessTypeUrlForwarderConfigurator) {
     main_routine = &UrlForwarderConfiguratorMain;
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
