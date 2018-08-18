--- chrome/browser/ssl/ssl_error_controller_client.cc.orig	2018-03-03 21:13:39.612526000 +0100
+++ chrome/browser/ssl/ssl_error_controller_client.cc	2018-03-03 21:14:15.298290000 +0100
@@ -55,7 +55,7 @@
 #if defined(OS_ANDROID)
   chrome::android::OpenDateAndTimeSettings();
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
@@ -185,7 +185,7 @@
 
 bool SSLErrorControllerClient::CanLaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   return true;
 #else
   return false;
