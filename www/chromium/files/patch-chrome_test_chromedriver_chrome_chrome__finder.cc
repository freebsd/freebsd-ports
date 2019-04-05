--- chrome/test/chromedriver/chrome/chrome_finder.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/test/chromedriver/chrome/chrome_finder.cc
@@ -48,7 +48,7 @@ void GetApplicationDirs(std::vector<base::FilePath>* l
         installation_locations[i].Append(L"Chromium\\Application"));
   }
 }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 void GetApplicationDirs(std::vector<base::FilePath>* locations) {
   // TODO: Respect users' PATH variables.
   // Until then, we use an approximation of the most common defaults.
@@ -135,7 +135,7 @@ bool FindChrome(base::FilePath* browser_exe) {
 #elif defined(OS_MACOSX)
       base::FilePath("Google Chrome.app/Contents/MacOS/Google Chrome"),
       base::FilePath("Chromium.app/Contents/MacOS/Chromium")
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
       base::FilePath("google-chrome"),
       base::FilePath("chrome"),
       base::FilePath("chromium"),
