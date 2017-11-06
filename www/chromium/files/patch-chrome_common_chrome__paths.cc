--- chrome/common/chrome_paths.cc.orig	2017-06-15 21:03:02.000000000 +0200
+++ chrome/common/chrome_paths.cc	2017-06-18 01:09:20.663411000 +0200
@@ -51,14 +51,14 @@
 const base::FilePath::CharType kInternalNaClPluginFileName[] =
     FILE_PATH_LITERAL("internal-nacl-plugin");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // The path to the external extension <id>.json files.
 // /usr/share seems like a good choice, see: http://www.pathname.com/fhs/
 const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
 #if defined(GOOGLE_CHROME_BUILD)
     FILE_PATH_LITERAL("/usr/share/google-chrome/extensions");
 #else
-    FILE_PATH_LITERAL("/usr/share/chromium/extensions");
+    FILE_PATH_LITERAL("/usr/local/share/chromium/extensions");
 #endif  // defined(GOOGLE_CHROME_BUILD)
 
 // The path to the hint file that tells the pepper plugin loader
@@ -190,7 +190,7 @@
         return false;
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur))
         return false;
       break;
@@ -426,7 +426,7 @@
       break;
 #endif
 #if BUILDFLAG(ENABLE_SUPERVISED_USERS)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case chrome::DIR_SUPERVISED_USERS_DEFAULT_APPS:
       if (!PathService::Get(chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS, &cur))
         return false;
@@ -474,10 +474,12 @@
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
@@ -485,7 +487,7 @@
     }
 #endif
 #if defined(OS_CHROMEOS) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD)) || \
-    defined(OS_MACOSX)
+    defined(OS_MACOSX) || defined(OS_BSD)
     case chrome::DIR_USER_EXTERNAL_EXTENSIONS: {
       if (!PathService::Get(chrome::DIR_USER_DATA, &cur))
         return false;
@@ -493,7 +495,7 @@
       break;
     }
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -528,7 +530,7 @@
 #endif
       break;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if defined(OS_MACOSX)
 #if defined(GOOGLE_CHROME_BUILD)
@@ -542,6 +544,9 @@
 #if defined(GOOGLE_CHROME_BUILD)
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/opt/chrome/native-messaging-hosts"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/native-messaging-hosts"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/chromium/native-messaging-hosts"));
@@ -554,7 +559,7 @@
         return false;
       cur = cur.Append(FILE_PATH_LITERAL("NativeMessagingHosts"));
       break;
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
     case chrome::DIR_GLOBAL_GCM_STORE:
       if (!PathService::Get(chrome::DIR_USER_DATA, &cur))
