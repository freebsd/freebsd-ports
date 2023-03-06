--- src/3rdparty/chromium/ui/base/clipboard/clipboard_data_endpoint.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_data_endpoint.h
@@ -15,9 +15,9 @@ enum class EndpointType {
 // destination trying to read the clipboard data.
 // Whenever a new format is supported, a new enum should be added.
 enum class EndpointType {
-#if defined(OS_CHROMEOS) || (OS_LINUX) || (OS_FUCHSIA)
+#if defined(OS_CHROMEOS) || (OS_LINUX) || (OS_FUCHSIA) || defined(OS_BSD)
   kGuestOs = 0,  // Guest OS: PluginVM, Crostini.
-#endif           // defined(OS_CHROMEOS) || (OS_LINUX) || (OS_FUCHSIA)
+#endif           // defined(OS_CHROMEOS) || (OS_LINUX) || (OS_FUCHSIA) || defined(OS_BSD)
 #if defined(OS_CHROMEOS)
   kArc = 1,               // ARC.
 #endif                    // defined(OS_CHROMEOS)
