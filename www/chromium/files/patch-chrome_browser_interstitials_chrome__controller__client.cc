--- chrome/browser/interstitials/chrome_controller_client.cc.orig	2016-04-08 16:02:07 UTC
+++ chrome/browser/interstitials/chrome_controller_client.cc
@@ -55,7 +55,7 @@ void LaunchDateAndTimeSettingsOnFile() {
   chrome::ShowSettingsSubPageForProfile(ProfileManager::GetActiveUserProfile(),
                                         sub_page);
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* pathname;
     const char* argument;
@@ -138,7 +138,7 @@ void ChromeControllerClient::set_interst
 
 bool ChromeControllerClient::CanLaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_MACOSX) || defined(OS_WIN)
+    defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   return true;
 #else
   return false;
