--- chrome/test/chromedriver/chrome_launcher.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -75,6 +75,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
