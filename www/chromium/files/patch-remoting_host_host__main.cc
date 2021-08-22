--- remoting/host/host_main.cc.orig	2021-07-19 18:45:20 UTC
+++ remoting/host/host_main.cc
@@ -47,9 +47,9 @@ int DesktopProcessMain();
 int FileChooserMain();
 int RdpDesktopSessionMain();
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 int XSessionChooserMain();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace {
 
@@ -60,10 +60,14 @@ const char kUsageMessage[] =
     "\n"
     "Options:\n"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
+#if defined(OS_LINUX)
     "Linux.\n"
-#endif  // defined(OS_LINUX)
+#else
+    "FreeBSD.\n"
+#endif
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(OS_APPLE)
     "  --list-audio-devices     - List all audio devices and their device "
@@ -147,10 +151,10 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
   } else if (process_type == kProcessTypeRdpDesktopSession) {
     main_routine = &RdpDesktopSessionMain;
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   }
 
   return main_routine;
