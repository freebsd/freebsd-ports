--- chrome/test/chromedriver/chrome_launcher.cc.orig	2023-07-24 14:27:53 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -66,6 +66,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
