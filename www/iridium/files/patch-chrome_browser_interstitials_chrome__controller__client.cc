--- chrome/browser/interstitials/chrome_controller_client.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/interstitials/chrome_controller_client.cc
@@ -46,7 +46,7 @@ void LaunchDateAndTimeSettingsOnFileThre
 #if defined(OS_ANDROID)
   chrome::android::OpenDateAndTimeSettings();
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
@@ -131,7 +131,7 @@ ChromeControllerClient::~ChromeControlle
 
 bool ChromeControllerClient::CanLaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_MACOSX) || defined(OS_WIN)
+    defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   return true;
 #else
   return false;
