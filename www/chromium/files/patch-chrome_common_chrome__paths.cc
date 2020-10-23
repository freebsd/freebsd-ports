--- chrome/common/chrome_paths.cc.orig	2020-09-08 19:14:01 UTC
+++ chrome/common/chrome_paths.cc
@@ -52,21 +52,21 @@ const base::FilePath::CharType kPepperFlashSystemBaseD
     FILE_PATH_LITERAL("Internet Plug-Ins/PepperFlashPlayer");
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // The path to the external extension <id>.json files.
 // /usr/share seems like a good choice, see: http://www.pathname.com/fhs/
 const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
-    FILE_PATH_LITERAL("/usr/share/google-chrome/extensions");
+    FILE_PATH_LITERAL("/usr/local/share/google-chrome/extensions");
 #else
-    FILE_PATH_LITERAL("/usr/share/chromium/extensions");
+    FILE_PATH_LITERAL("/usr/local/share/chromium/extensions");
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
 // The path to the hint file that tells the pepper plugin loader
 // where it can find the latest component updated flash.
 const base::FilePath::CharType kComponentUpdatedFlashHint[] =
     FILE_PATH_LITERAL("latest-component-updated-flash");
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_LINUX) && BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)
 // The name of the hint file that tells the latest component updated Widevine
@@ -205,7 +205,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur))
         return false;
       break;
@@ -490,6 +490,9 @@ bool PathProvider(int key, base::FilePath* result) {
     case chrome::DIR_POLICY_FILES: {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/opt/chrome/policies"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/policies"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/chromium/policies"));
 #endif
@@ -497,7 +500,7 @@ bool PathProvider(int key, base::FilePath* result) {
     }
 #endif
 #if defined(OS_CHROMEOS) || \
-    (defined(OS_LINUX) && BUILDFLAG(CHROMIUM_BRANDING)) || defined(OS_MACOSX)
+    ((defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(CHROMIUM_BRANDING)) || defined(OS_MACOSX)
     case chrome::DIR_USER_EXTERNAL_EXTENSIONS: {
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur))
         return false;
@@ -505,7 +508,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
     }
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -540,7 +543,7 @@ bool PathProvider(int key, base::FilePath* result) {
 #endif
       break;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if defined(OS_MACOSX)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
@@ -554,6 +557,9 @@ bool PathProvider(int key, base::FilePath* result) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/opt/chrome/native-messaging-hosts"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/native-messaging-hosts"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/chromium/native-messaging-hosts"));
@@ -566,7 +572,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       cur = cur.Append(FILE_PATH_LITERAL("NativeMessagingHosts"));
       break;
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
     case chrome::DIR_GLOBAL_GCM_STORE:
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur))
@@ -574,7 +580,7 @@ bool PathProvider(int key, base::FilePath* result) {
       cur = cur.Append(kGCMStoreDirname);
       break;
 #endif  // !defined(OS_ANDROID)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case chrome::FILE_COMPONENT_FLASH_HINT:
       if (!base::PathService::Get(
               chrome::DIR_COMPONENT_UPDATED_PEPPER_FLASH_PLUGIN, &cur)) {
@@ -582,7 +588,7 @@ bool PathProvider(int key, base::FilePath* result) {
       }
       cur = cur.Append(kComponentUpdatedFlashHint);
       break;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 #if defined(OS_CHROMEOS)
     case chrome::FILE_CHROME_OS_COMPONENT_FLASH:
       cur = base::FilePath(kChromeOSComponentFlash);
