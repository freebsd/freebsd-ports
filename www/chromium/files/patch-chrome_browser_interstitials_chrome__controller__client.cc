--- chrome/browser/interstitials/chrome_controller_client.cc.orig	2017-01-26 00:49:08 UTC
+++ chrome/browser/interstitials/chrome_controller_client.cc
@@ -49,7 +49,7 @@ void LaunchDateAndTimeSettingsOnFileThre
 #if defined(OS_ANDROID)
   chrome::android::OpenDateAndTimeSettings();
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
@@ -136,7 +136,7 @@ void ChromeControllerClient::set_interst
 
 bool ChromeControllerClient::CanLaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_MACOSX) || defined(OS_WIN)
+    defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   return true;
 #else
   return false;
