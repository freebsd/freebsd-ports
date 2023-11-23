--- chrome/browser/ui/browser_dialogs.h.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/ui/browser_dialogs.h
@@ -26,7 +26,7 @@
 #include "ui/gfx/native_widget_types.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/web_app_callback_app_identity.h"
 #include "chrome/browser/web_applications/web_app_id.h"
 #include "chrome/browser/web_applications/web_app_install_info.h"
@@ -84,7 +84,7 @@ class Widget;
 }  // namespace views
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 namespace webapps {
 class MlInstallOperationTracker;
 struct Screenshot;
@@ -162,7 +162,7 @@ void ShowBluetoothDevicePairConfirmDialog(
 #endif  // PAIR_BLUETOOTH_ON_DEMAND()
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Callback used to indicate whether a user has accepted the installation of a
 // web app. The boolean parameter is true when the user accepts the dialog. The
 // WebAppInstallInfo parameter contains the information about the app,
