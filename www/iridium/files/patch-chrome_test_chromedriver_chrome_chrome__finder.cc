--- chrome/test/chromedriver/chrome/chrome_finder.cc.orig	2020-02-24 18:39:10 UTC
+++ chrome/test/chromedriver/chrome/chrome_finder.cc
@@ -50,7 +50,7 @@ void GetApplicationDirs(std::vector<base::FilePath>* l
         installation_locations[i].Append(L"Chromium\\Application"));
   }
 }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 void GetApplicationDirs(std::vector<base::FilePath>* locations) {
   // TODO: Respect users' PATH variables.
   // Until then, we use an approximation of the most common defaults.
@@ -136,7 +136,7 @@ bool FindChrome(base::FilePath* browser_exe) {
 #if defined(OS_WIN) || defined(OS_MACOSX)
     base::FilePath(chrome::kBrowserProcessExecutablePath),
     base::FilePath(chrome::kBrowserProcessExecutablePathChromium)
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     base::FilePath("google-chrome"),
     base::FilePath(chrome::kBrowserProcessExecutablePath),
     base::FilePath(chrome::kBrowserProcessExecutablePathChromium),
