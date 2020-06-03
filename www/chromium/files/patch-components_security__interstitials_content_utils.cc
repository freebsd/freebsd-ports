--- components/security_interstitials/content/utils.cc.orig	2020-05-15 15:04:01 UTC
+++ components/security_interstitials/content/utils.cc
@@ -31,12 +31,18 @@ void LaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID)
   JNIEnv* env = base::android::AttachCurrentThread();
   Java_DateAndTimeSettingsHelper_openDateAndTimeSettings(env);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
   };
   static const ClockCommand kClockCommands[] = {
+#if defined(OS_BSD)
+      // GNOME
+      {"/usr/local/bin/gnome-control-center", "datetime"},
+      // KDE
+      {"/usr/local/bin/kcmshell4", "clock"},
+#else
       // Unity
       {"/usr/bin/unity-control-center", "datetime"},
       // GNOME
@@ -50,6 +56,7 @@ void LaunchDateAndTimeSettings() {
       {"/usr/bin/kcmshell4", "clock"},
       {"/usr/local/bin/kcmshell4", "clock"},
       {"/opt/bin/kcmshell4", "clock"},
+#endif
   };
 
   base::CommandLine command(base::FilePath(""));
