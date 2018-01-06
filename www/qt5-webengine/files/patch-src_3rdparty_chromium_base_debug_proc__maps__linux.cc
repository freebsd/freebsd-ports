--- src/3rdparty/chromium/base/debug/proc_maps_linux.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/debug/proc_maps_linux.cc
@@ -12,7 +12,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
 #include <inttypes.h>
 #endif
 
