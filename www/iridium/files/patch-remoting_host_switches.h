--- remoting/host/switches.h.orig	2019-10-30 16:21:42 UTC
+++ remoting/host/switches.h
@@ -34,9 +34,9 @@ extern const char kProcessTypeHost[];
 extern const char kProcessTypeRdpDesktopSession[];
 extern const char kProcessTypeEvaluateCapability[];
 extern const char kProcessTypeFileChooser[];
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kProcessTypeXSessionChooser[];
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kEvaluateCapabilitySwitchName[];
 
