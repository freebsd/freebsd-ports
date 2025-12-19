--- src/3rdparty/chromium/chrome/test/chromedriver/chrome_launcher.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/test/chromedriver/chrome_launcher.cc
@@ -73,6 +73,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
