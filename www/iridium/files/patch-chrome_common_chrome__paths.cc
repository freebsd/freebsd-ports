--- chrome/common/chrome_paths.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/common/chrome_paths.cc
@@ -30,7 +30,7 @@
 #include "base/apple/foundation_util.h"
 #endif
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
 #include "components/policy/core/common/policy_paths.h"
 #endif
 
@@ -51,14 +51,14 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // The path to the external extension <id>.json files.
 // /usr/share seems like a good choice, see: http://www.pathname.com/fhs/
 const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
-    FILE_PATH_LITERAL("/usr/share/google-chrome/extensions");
+    FILE_PATH_LITERAL("/usr/local/share/iridium/extensions");
 #else
-    FILE_PATH_LITERAL("/usr/share/chromium/extensions");
+    FILE_PATH_LITERAL("/usr/local/share/iridium/extensions");
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -213,7 +213,7 @@ bool PathProvider(int key, base::FilePath* result) {
       }
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur)) {
         return false;
       }
@@ -516,7 +516,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       }
       break;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
     case chrome::DIR_POLICY_FILES: {
       cur = base::FilePath(policy::kPolicyPath);
       break;
@@ -527,7 +527,7 @@ bool PathProvider(int key, base::FilePath* result) {
 #if BUILDFLAG(IS_CHROMEOS_ASH) ||                              \
     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
      BUILDFLAG(CHROMIUM_BRANDING)) ||                          \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case chrome::DIR_USER_EXTERNAL_EXTENSIONS: {
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur)) {
         return false;
@@ -536,7 +536,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
     }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -583,7 +583,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if BUILDFLAG(IS_MAC)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
@@ -595,11 +595,21 @@ bool PathProvider(int key, base::FilePath* result) {
 #endif
 #else  // BUILDFLAG(IS_MAC)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
+#if BUILDFLAG(IS_FREEBSD)
       cur = base::FilePath(
-          FILE_PATH_LITERAL("/etc/iridium-browser/native-messaging-hosts"));
+          FILE_PATH_LITERAL("/usr/local/etc/iridium/native-messaging-hosts"));
 #else
       cur = base::FilePath(
-          FILE_PATH_LITERAL("/etc/iridium-browser/native-messaging-hosts"));
+          FILE_PATH_LITERAL("/etc/iridium/native-messaging-hosts"));
+#endif
+#else
+#if BUILDFLAG(IS_FREEBSD)
+      cur = base::FilePath(
+          FILE_PATH_LITERAL("/usr/local/etc/iridium/native-messaging-hosts"));
+#else
+      cur = base::FilePath(
+          FILE_PATH_LITERAL("/etc/iridium/native-messaging-hosts"));
+#endif
 #endif
 #endif  // !BUILDFLAG(IS_MAC)
       break;
