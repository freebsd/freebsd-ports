Chase https://github.com/Netflix/vmaf/commit/82a86e040371

source/encoder/api.cpp:36:10: fatal error: 'libvmaf.h' file not found
#include "libvmaf.h"
         ^~~~~~~~~~~

--- source/encoder/api.cpp.orig	2019-10-29 11:55:05 UTC
+++ source/encoder/api.cpp
@@ -33,7 +33,7 @@
 #include "svt.h"
 
 #if ENABLE_LIBVMAF
-#include "libvmaf.h"
+#include "libvmaf/libvmaf.h"
 #endif
 
 /* multilib namespace reflectors */
