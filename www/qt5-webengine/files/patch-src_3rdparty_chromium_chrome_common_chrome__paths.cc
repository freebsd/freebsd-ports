--- src/3rdparty/chromium/chrome/common/chrome_paths.cc.orig	2017-01-26 00:49:09 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_paths.cc
@@ -197,7 +197,7 @@ bool PathProvider(int key, base::FilePat
         return false;
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur))
         return false;
       break;
@@ -480,10 +480,12 @@ bool PathProvider(int key, base::FilePat
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
@@ -534,7 +536,7 @@ bool PathProvider(int key, base::FilePat
 #endif
       break;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if defined(OS_MACOSX)
 #if defined(GOOGLE_CHROME_BUILD)
@@ -548,6 +550,9 @@ bool PathProvider(int key, base::FilePat
 #if defined(GOOGLE_CHROME_BUILD)
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/opt/chrome/native-messaging-hosts"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/native-messaging-hosts"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/chromium/native-messaging-hosts"));
@@ -560,7 +565,7 @@ bool PathProvider(int key, base::FilePat
         return false;
       cur = cur.Append(FILE_PATH_LITERAL("NativeMessagingHosts"));
       break;
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
     case chrome::DIR_GLOBAL_GCM_STORE:
       if (!PathService::Get(chrome::DIR_USER_DATA, &cur))
