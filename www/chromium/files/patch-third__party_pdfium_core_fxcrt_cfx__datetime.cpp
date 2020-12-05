--- third_party/pdfium/core/fxcrt/cfx_datetime.cpp.orig	2020-11-13 06:42:20 UTC
+++ third_party/pdfium/core/fxcrt/cfx_datetime.cpp
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 #include "core/fxcrt/fx_system.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_APPLE) || defined(OS_ASMJS)
 #include <sys/time.h>
 #include <time.h>
