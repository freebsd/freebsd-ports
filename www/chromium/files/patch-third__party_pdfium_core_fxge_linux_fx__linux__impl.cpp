--- third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp.orig	2021-07-28 09:23:50 UTC
+++ third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp
@@ -17,7 +17,7 @@
 #include "third_party/base/check.h"
 #include "third_party/base/stl_util.h"
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ASMJS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ASMJS) && !defined(OS_BSD)
 #error "Included on the wrong platform"
 #endif
 
