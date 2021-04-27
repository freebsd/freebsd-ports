--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc
@@ -190,7 +190,7 @@ const struct {
     {base::DIR_APP_DATA, nullptr, kBlockAllChildren},
     {base::DIR_HOME, FILE_PATH_LITERAL("Library"), kBlockAllChildren},
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // On Linux also block access to devices via /dev, as well as security
     // sensitive data in /sys and /proc.
     {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), kBlockAllChildren},
