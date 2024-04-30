--- src/3rdparty/chromium/chrome/test/chromedriver/chrome_launcher.cc.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/chrome/test/chromedriver/chrome_launcher.cc
@@ -69,6 +69,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
