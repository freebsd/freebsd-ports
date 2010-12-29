--- ./xbmc/utils/Stopwatch.cpp.orig	2010-06-25 23:43:57.000000000 +0200
+++ ./xbmc/utils/Stopwatch.cpp	2010-12-01 12:17:34.282082217 +0100
@@ -20,7 +20,7 @@
  */
 
 #include "Stopwatch.h"
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/sysinfo.h>
 #endif
 #include "utils/TimeUtils.h"
