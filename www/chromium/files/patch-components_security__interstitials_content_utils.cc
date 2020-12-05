--- components/security_interstitials/content/utils.cc.orig	2020-11-13 06:36:41 UTC
+++ components/security_interstitials/content/utils.cc
@@ -31,7 +31,7 @@ void LaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID)
   JNIEnv* env = base::android::AttachCurrentThread();
   Java_DateAndTimeSettingsHelper_openDateAndTimeSettings(env);
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
