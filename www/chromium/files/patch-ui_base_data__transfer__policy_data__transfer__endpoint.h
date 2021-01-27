--- ui/base/data_transfer_policy/data_transfer_endpoint.h.orig	2021-01-19 11:52:05 UTC
+++ ui/base/data_transfer_policy/data_transfer_endpoint.h
@@ -17,9 +17,9 @@ namespace ui {
 enum class EndpointType {
   kDefault = 0,  // This type shouldn't be used if any of the following types is
                  // a better match.
-#if defined(OS_CHROMEOS) || (OS_LINUX) || (OS_FUCHSIA)
+#if defined(OS_CHROMEOS) || (OS_LINUX) || (OS_FUCHSIA) || defined(OS_BSD)
   kGuestOs = 1,  // Guest OS: PluginVM, Crostini.
-#endif           // defined(OS_CHROMEOS) || (OS_LINUX) || (OS_FUCHSIA)
+#endif           // defined(OS_CHROMEOS) || (OS_LINUX) || (OS_FUCHSIA) || defined(OS_BSD)
 #if defined(OS_CHROMEOS)
   kArc = 2,               // ARC.
 #endif                    // defined(OS_CHROMEOS)
