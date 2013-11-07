--- wpagui.cpp.orig	2010-09-07 19:43:39.000000000 +0400
+++ wpagui.cpp	2013-11-07 14:07:50.086773239 +0400
@@ -12,10 +12,7 @@
  * See README and COPYING for more details.
  */
 
-#ifdef __MINGW32__
-/* Need to get getopt() */
 #include <unistd.h>
-#endif
 
 #ifdef CONFIG_NATIVE_WINDOWS
 #include <windows.h>
@@ -27,6 +24,8 @@
 #include <QImageReader>
 #include <QSettings>
 
+#include <getopt.h>
+
 #include "wpagui.h"
 #include "dirent.h"
 #include "common/wpa_ctrl.h"
