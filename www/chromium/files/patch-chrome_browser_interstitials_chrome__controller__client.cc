--- chrome/browser/interstitials/chrome_controller_client.cc.orig	2017-12-15 02:04:09.000000000 +0100
+++ chrome/browser/interstitials/chrome_controller_client.cc	2017-12-24 01:30:40.740189000 +0100
@@ -46,7 +46,7 @@
 #if defined(OS_ANDROID)
   chrome::android::OpenDateAndTimeSettings();
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
@@ -130,7 +130,7 @@
 
 bool ChromeControllerClient::CanLaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   return true;
 #else
   return false;
