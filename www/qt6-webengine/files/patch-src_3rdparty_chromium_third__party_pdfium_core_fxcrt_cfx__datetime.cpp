--- src/3rdparty/chromium/third_party/pdfium/core/fxcrt/cfx_datetime.cpp.orig	2022-11-06 22:18:10 UTC
+++ src/3rdparty/chromium/third_party/pdfium/core/fxcrt/cfx_datetime.cpp
@@ -11,7 +11,7 @@
 #include "third_party/base/check.h"
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_APPLE) || defined(OS_ASMJS)
+    BUILDFLAG(IS_APPLE) || defined(OS_ASMJS) || BUILDFLAG(IS_BSD)
 #include <sys/time.h>
 #include <time.h>
 #endif
