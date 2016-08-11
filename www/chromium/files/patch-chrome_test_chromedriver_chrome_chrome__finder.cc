--- chrome/test/chromedriver/chrome/chrome_finder.cc.orig	2016-03-25 13:04:46 UTC
+++ chrome/test/chromedriver/chrome/chrome_finder.cc
@@ -45,7 +45,7 @@ void GetApplicationDirs(std::vector<base
         installation_locations[i].Append(L"Chromium\\Application"));
   }
 }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 void GetApplicationDirs(std::vector<base::FilePath>* locations) {
   locations->push_back(base::FilePath("/opt/google/chrome"));
   locations->push_back(base::FilePath("/usr/local/bin"));
@@ -95,7 +95,7 @@ bool FindChrome(base::FilePath* browser_
 #elif defined(OS_MACOSX)
       base::FilePath("Google Chrome.app/Contents/MacOS/Google Chrome"),
       base::FilePath("Chromium.app/Contents/MacOS/Chromium")
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
       base::FilePath("google-chrome"),
       base::FilePath("chrome"),
       base::FilePath("chromium"),
