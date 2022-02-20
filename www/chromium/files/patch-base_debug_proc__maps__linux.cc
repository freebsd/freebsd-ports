--- base/debug/proc_maps_linux.cc.orig	2022-02-07 13:39:41 UTC
+++ base/debug/proc_maps_linux.cc
@@ -13,7 +13,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <inttypes.h>
 #endif
 
