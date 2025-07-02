--- chrome/test/chromedriver/chrome_launcher.cc.orig	2025-07-02 06:08:04 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -74,6 +74,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
