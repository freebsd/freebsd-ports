--- chrome/common/chrome_paths.cc.orig	2019-12-16 21:50:44 UTC
+++ chrome/common/chrome_paths.cc
@@ -51,21 +51,21 @@ const base::FilePath::CharType kPepperFlashSystemBaseD
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
@@ -204,7 +204,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur))
         return false;
       break;
@@ -502,7 +502,7 @@ bool PathProvider(int key, base::FilePath* result) {
     }
 #endif
 #if defined(OS_CHROMEOS) || \
-    (defined(OS_LINUX) && BUILDFLAG(CHROMIUM_BRANDING)) || defined(OS_MACOSX)
+    ((defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(CHROMIUM_BRANDING)) || defined(OS_MACOSX)
     case chrome::DIR_USER_EXTERNAL_EXTENSIONS: {
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur))
         return false;
@@ -510,7 +510,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
     }
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -545,7 +545,7 @@ bool PathProvider(int key, base::FilePath* result) {
 #endif
       break;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if defined(OS_MACOSX)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
@@ -559,6 +559,9 @@ bool PathProvider(int key, base::FilePath* result) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/opt/chrome/native-messaging-hosts"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/native-messaging-hosts"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/chromium/native-messaging-hosts"));
@@ -571,7 +574,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       cur = cur.Append(FILE_PATH_LITERAL("NativeMessagingHosts"));
       break;
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
     case chrome::DIR_GLOBAL_GCM_STORE:
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur))
@@ -579,7 +582,7 @@ bool PathProvider(int key, base::FilePath* result) {
       cur = cur.Append(kGCMStoreDirname);
       break;
 #endif  // !defined(OS_ANDROID)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case chrome::FILE_COMPONENT_FLASH_HINT:
       if (!base::PathService::Get(
               chrome::DIR_COMPONENT_UPDATED_PEPPER_FLASH_PLUGIN, &cur)) {
@@ -587,7 +590,7 @@ bool PathProvider(int key, base::FilePath* result) {
       }
       cur = cur.Append(kComponentUpdatedFlashHint);
       break;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 #if defined(OS_CHROMEOS)
     case chrome::FILE_CHROME_OS_COMPONENT_FLASH:
       cur = base::FilePath(kChromeOSComponentFlash);
