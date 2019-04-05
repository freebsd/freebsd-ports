--- src/3rdparty/chromium/chrome/common/chrome_paths.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_paths.cc
@@ -193,7 +193,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur))
         return false;
       break;
@@ -472,10 +472,12 @@ bool PathProvider(int key, base::FilePath* result) {
       if (!base::PathExists(cur))  // We don't want to create this
         return false;
       break;
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD)
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
     case chrome::DIR_POLICY_FILES: {
 #if defined(GOOGLE_CHROME_BUILD)
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/opt/chrome/policies"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL("/usr/local/etc/chrome/policies"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/chromium/policies"));
 #endif
@@ -526,7 +528,7 @@ bool PathProvider(int key, base::FilePath* result) {
 #endif
       break;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if defined(OS_MACOSX)
 #if defined(GOOGLE_CHROME_BUILD)
@@ -540,6 +542,9 @@ bool PathProvider(int key, base::FilePath* result) {
 #if defined(GOOGLE_CHROME_BUILD)
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/opt/chrome/native-messaging-hosts"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/native-messaging-hosts"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/chromium/native-messaging-hosts"));
@@ -552,7 +557,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       cur = cur.Append(FILE_PATH_LITERAL("NativeMessagingHosts"));
       break;
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
     case chrome::DIR_GLOBAL_GCM_STORE:
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur))
