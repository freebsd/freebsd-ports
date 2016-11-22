--- base/debug/proc_maps_linux.cc.orig	2016-08-03 22:02:10.000000000 +0300
+++ base/debug/proc_maps_linux.cc	2016-09-05 22:49:53.622055000 +0300
@@ -12,7 +12,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
 #include <inttypes.h>
 #endif
 
