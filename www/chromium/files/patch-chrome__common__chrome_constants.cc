--- chrome/common/chrome_constants.cc.orig	2011-01-06 10:02:01.000000000 +0100
+++ chrome/common/chrome_constants.cc	2011-01-09 20:43:41.000000000 +0100
@@ -27,7 +27,7 @@
 #if defined(OS_WIN)
 const FilePath::CharType kBrowserProcessExecutableName[] = FPL("chrome.exe");
 const FilePath::CharType kHelperProcessExecutableName[] = FPL("chrome.exe");
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 const FilePath::CharType kBrowserProcessExecutableName[] = FPL("chrome");
 // Helper processes end up with a name of "exe" due to execing via
 // /proc/self/exe.  See bug 22703.
@@ -40,7 +40,7 @@
 #if defined(OS_WIN)
 const FilePath::CharType kBrowserProcessExecutablePath[] = FPL("chrome.exe");
 const FilePath::CharType kHelperProcessExecutablePath[] = FPL("chrome.exe");
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 const FilePath::CharType kBrowserProcessExecutablePath[] = FPL("chrome");
 const FilePath::CharType kHelperProcessExecutablePath[] = FPL("chrome");
 #elif defined(OS_MACOSX)
