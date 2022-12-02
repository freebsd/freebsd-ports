--- chrome/common/chrome_paths.cc.orig	2022-12-02 17:56:32 UTC
+++ chrome/common/chrome_paths.cc
@@ -49,14 +49,14 @@
 
 namespace {
 
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
@@ -178,7 +178,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur))
         return false;
       break;
@@ -421,12 +421,14 @@ bool PathProvider(int key, base::FilePath* result) {
       if (!base::PathExists(cur))  // We don't want to create this
         return false;
       break;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
     case chrome::DIR_POLICY_FILES: {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/opt/chrome/policies"));
+#elif BUILDFLAG(IS_FREEBSD)
+      cur = base::FilePath(FILE_PATH_LITERAL("/usr/local/etc/ungoogled-chromium/policies"));
 #else
-      cur = base::FilePath(FILE_PATH_LITERAL("/etc/chromium/policies"));
+      cur = base::FilePath(FILE_PATH_LITERAL("/etc/ungoogled-chromium/policies"));
 #endif
       break;
     }
@@ -436,7 +438,7 @@ bool PathProvider(int key, base::FilePath* result) {
 #if BUILDFLAG(IS_CHROMEOS_ASH) ||                              \
     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
      BUILDFLAG(CHROMIUM_BRANDING)) ||                          \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case chrome::DIR_USER_EXTERNAL_EXTENSIONS: {
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur))
         return false;
@@ -444,7 +446,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
     }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -488,7 +490,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if BUILDFLAG(IS_MAC)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
@@ -502,9 +504,12 @@ bool PathProvider(int key, base::FilePath* result) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/opt/chrome/native-messaging-hosts"));
+#elif BUILDFLAG(IS_FREEBSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/ungoogled-chromium/native-messaging-hosts"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL(
-          "/etc/chromium/native-messaging-hosts"));
+          "/etc/ungoogled-chromium/native-messaging-hosts"));
 #endif
 #endif  // !BUILDFLAG(IS_MAC)
       break;
