--- chrome/common/chrome_paths.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/common/chrome_paths.cc
@@ -31,7 +31,7 @@
 #include "base/apple/foundation_util.h"
 #endif
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
 #include "components/policy/core/common/policy_paths.h"
 #endif
 
@@ -47,14 +47,14 @@ namespace {
 
 std::optional<bool> g_override_using_default_data_directory_for_testing;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // The path to the external extension <id>.json files.
 // /usr/share seems like a good choice, see: http://www.pathname.com/fhs/
 const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
-    FILE_PATH_LITERAL("/usr/share/google-chrome/extensions");
+    FILE_PATH_LITERAL("/usr/local/share/ungoogled-chromium/extensions");
 #else
-    FILE_PATH_LITERAL("/usr/share/chromium/extensions");
+    FILE_PATH_LITERAL("/usr/local/share/ungoogled-chromium/extensions");
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -176,7 +176,7 @@ bool PathProvider(int key, base::FilePath* result) {
       }
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur)) {
         return false;
       }
@@ -407,13 +407,13 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
     }
 #endif
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
     case chrome::DIR_POLICY_FILES: {
       cur = base::FilePath(policy::kPolicyPath);
       break;
     }
 #endif
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && BUILDFLAG(CHROMIUM_BRANDING))
     case chrome::DIR_USER_EXTERNAL_EXTENSIONS: {
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur)) {
@@ -423,7 +423,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
     }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -462,7 +462,7 @@ bool PathProvider(int key, base::FilePath* result) {
 
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE) &&                                   \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_ANDROID))
+     BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
     case chrome::DIR_NATIVE_MESSAGING:
 #if BUILDFLAG(IS_MAC)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
@@ -476,9 +476,12 @@ bool PathProvider(int key, base::FilePath* result) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(
           FILE_PATH_LITERAL("/etc/opt/chrome/native-messaging-hosts"));
+#elif BUILDFLAG(IS_FREEBSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/ungoogled-chromium/native-messaging-hosts"));
 #else
       cur = base::FilePath(
-          FILE_PATH_LITERAL("/etc/chromium/native-messaging-hosts"));
+          FILE_PATH_LITERAL("/etc/ungoogled-chromium/native-messaging-hosts"));
 #endif
 #endif  // !BUILDFLAG(IS_MAC)
       break;
