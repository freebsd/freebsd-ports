--- chrome/common/chrome_paths.cc.orig	2023-12-10 06:10:27 UTC
+++ chrome/common/chrome_paths.cc
@@ -30,7 +30,7 @@
 #include "base/apple/foundation_util.h"
 #endif
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
 #include "components/policy/core/common/policy_paths.h"
 #endif
 
@@ -52,14 +52,14 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // The path to the external extension <id>.json files.
 // /usr/share seems like a good choice, see: http://www.pathname.com/fhs/
 const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
-    FILE_PATH_LITERAL("/usr/share/google-chrome/extensions");
+    FILE_PATH_LITERAL("/usr/local/share/chromium/extensions");
 #else
-    FILE_PATH_LITERAL("/usr/share/chromium/extensions");
+    FILE_PATH_LITERAL("/usr/local/share/chromium/extensions");
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -220,7 +220,7 @@ bool PathProvider(int key, base::FilePath* result) {
       }
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur)) {
         return false;
       }
@@ -523,7 +523,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       }
       break;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
     case chrome::DIR_POLICY_FILES: {
       cur = base::FilePath(policy::kPolicyPath);
       break;
@@ -534,7 +534,7 @@ bool PathProvider(int key, base::FilePath* result) {
 #if BUILDFLAG(IS_CHROMEOS_ASH) ||                              \
     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
      BUILDFLAG(CHROMIUM_BRANDING)) ||                          \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case chrome::DIR_USER_EXTERNAL_EXTENSIONS: {
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur)) {
         return false;
@@ -543,7 +543,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
     }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -590,7 +590,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if BUILDFLAG(IS_MAC)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
@@ -604,6 +604,9 @@ bool PathProvider(int key, base::FilePath* result) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(
           FILE_PATH_LITERAL("/etc/opt/chrome/native-messaging-hosts"));
+#elif BUILDFLAG(IS_FREEBSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chromium/native-messaging-hosts"));
 #else
       cur = base::FilePath(
           FILE_PATH_LITERAL("/etc/chromium/native-messaging-hosts"));
