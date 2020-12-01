--- ui/base/clipboard/clipboard_data_endpoint.h.orig	2020-11-16 14:59:26 UTC
+++ ui/base/clipboard/clipboard_data_endpoint.h
@@ -15,9 +15,9 @@ namespace ui {
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
