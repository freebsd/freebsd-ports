--- chrome/test/chromedriver/chrome/chrome_finder.cc.orig	2014-10-10 08:54:12 UTC
+++ chrome/test/chromedriver/chrome/chrome_finder.cc
@@ -42,7 +42,7 @@
         installation_locations[i].Append(L"Chromium\\Application"));
   }
 }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 void GetApplicationDirs(std::vector<base::FilePath>* locations) {
   locations->push_back(base::FilePath("/opt/google/chrome"));
   locations->push_back(base::FilePath("/usr/local/bin"));
@@ -92,7 +92,7 @@
 #elif defined(OS_MACOSX)
       base::FilePath("Google Chrome.app/Contents/MacOS/Google Chrome"),
       base::FilePath("Chromium.app/Contents/MacOS/Chromium")
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
       base::FilePath("google-chrome"),
       base::FilePath("chrome"),
       base::FilePath("chromium"),
