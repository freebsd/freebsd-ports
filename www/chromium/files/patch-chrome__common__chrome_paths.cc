--- chrome/common/chrome_paths.cc.orig	2014-10-10 08:54:11 UTC
+++ chrome/common/chrome_paths.cc
@@ -461,10 +461,12 @@
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
@@ -542,7 +544,7 @@
 #endif
       break;
 
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#if defined(OS_LINUX) || defined(OS_BSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
     case chrome::DIR_NATIVE_MESSAGING:
 #if defined(OS_MACOSX)
 #if defined(GOOGLE_CHROME_BUILD)
@@ -556,6 +558,9 @@
 #if defined(GOOGLE_CHROME_BUILD)
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/opt/chrome/native-messaging-hosts"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/native-messaging-hosts"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/chromium/native-messaging-hosts"));
@@ -568,7 +573,7 @@
         return false;
       cur = cur.Append(FILE_PATH_LITERAL("NativeMessagingHosts"));
       break;
-#endif  // defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
 #if !defined(OS_ANDROID)
     case chrome::DIR_GLOBAL_GCM_STORE:
       if (!PathService::Get(chrome::DIR_USER_DATA, &cur))
