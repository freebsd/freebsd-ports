--- content/common/gpu/x_util.h.orig	2010-12-16 02:11:58.000000000 +0100
+++ content/common/gpu/x_util.h	2010-12-20 20:15:08.000000000 +0100
@@ -12,7 +12,7 @@
 #include "build/build_config.h"
 #include "chrome/gpu/gpu_config.h"
 
-#if defined(OS_LINUX)
+#if defined(USE_X11)
 
 // Forward declares ------------------------------------------------------------
 //
@@ -42,6 +42,6 @@
   void operator()(void* x) const;
 };
 
-#endif  // OS_LINUX
+#endif  // USE_X11
 
 #endif  // CHROME_GPU_X_UTIL_H_
