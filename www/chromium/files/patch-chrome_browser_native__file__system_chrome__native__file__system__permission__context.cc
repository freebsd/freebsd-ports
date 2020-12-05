--- chrome/browser/native_file_system/chrome_native_file_system_permission_context.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/native_file_system/chrome_native_file_system_permission_context.cc
@@ -138,7 +138,7 @@ const struct {
     {base::DIR_APP_DATA, nullptr, kBlockAllChildren},
     {base::DIR_HOME, FILE_PATH_LITERAL("Library"), kBlockAllChildren},
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // On Linux also block access to devices via /dev, as well as security
     // sensitive data in /sys and /proc.
     {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), kBlockAllChildren},
