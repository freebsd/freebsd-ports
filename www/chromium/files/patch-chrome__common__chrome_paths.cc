--- chrome/common/chrome_paths.cc.orig	2012-05-23 04:50:48.000000000 +0300
+++ chrome/common/chrome_paths.cc	2012-05-26 00:47:40.880289194 +0300
@@ -334,10 +334,12 @@
       if (!file_util::PathExists(cur))  // We don't want to create this
         return false;
       break;
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD)
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
     case chrome::DIR_POLICY_FILES: {
 #if defined(GOOGLE_CHROME_BUILD)
       cur = FilePath(FILE_PATH_LITERAL("/etc/opt/chrome/policies"));
+#elif defined(OS_BSD)
+      cur = FilePath(FILE_PATH_LITERAL("/usr/local/etc/chrome/policies"));
 #else
       cur = FilePath(FILE_PATH_LITERAL("/etc/chromium/policies"));
 #endif
