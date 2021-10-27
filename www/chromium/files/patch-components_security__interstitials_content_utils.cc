--- components/security_interstitials/content/utils.cc.orig	2021-09-24 04:26:04 UTC
+++ components/security_interstitials/content/utils.cc
@@ -34,7 +34,7 @@ void LaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID)
   JNIEnv* env = base::android::AttachCurrentThread();
   Java_DateAndTimeSettingsHelper_openDateAndTimeSettings(env);
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
