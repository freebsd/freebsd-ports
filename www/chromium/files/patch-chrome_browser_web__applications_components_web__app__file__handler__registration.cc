--- chrome/browser/web_applications/components/web_app_file_handler_registration.cc.orig	2020-03-03 18:53:53 UTC
+++ chrome/browser/web_applications/components/web_app_file_handler_registration.cc
@@ -15,7 +15,7 @@ namespace web_app {
 //
 // Note: Because OS_LINUX includes OS_CHROMEOS be sure to use the stub on
 // OS_CHROMEOS.
-#if !defined(OS_WIN) && !(defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if !defined(OS_WIN) && !(defined(OS_LINUX) && !defined(OS_CHROMEOS)) && !defined(OS_BSD)
 bool ShouldRegisterFileHandlersWithOs() {
   return false;
 }
