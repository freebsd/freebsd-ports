--- chrome/test/chromedriver/chrome/chrome_finder.cc.orig	2021-04-14 18:40:56 UTC
+++ chrome/test/chromedriver/chrome/chrome_finder.cc
@@ -53,7 +53,7 @@ void GetApplicationDirs(std::vector<base::FilePath>* l
         installation_locations[i].Append(L"Chromium\\Application"));
   }
 }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void GetApplicationDirs(std::vector<base::FilePath>* locations) {
   // TODO: Respect users' PATH variables.
   // Until then, we use an approximation of the most common defaults.
@@ -138,7 +138,7 @@ bool FindChrome(base::FilePath* browser_exe) {
   base::FilePath browser_exes_array[] = {
 #if defined(OS_WIN) || defined(OS_MAC)
     base::FilePath(chrome::kBrowserProcessExecutablePath),
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     base::FilePath("google-chrome"),
     base::FilePath(chrome::kBrowserProcessExecutablePath),
     base::FilePath("chromium"),
