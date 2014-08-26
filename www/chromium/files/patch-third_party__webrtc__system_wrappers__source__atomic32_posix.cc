--- ./third_party/webrtc/system_wrappers/source/atomic32_posix.cc.orig	2014-08-20 21:04:27.000000000 +0200
+++ ./third_party/webrtc/system_wrappers/source/atomic32_posix.cc	2014-08-22 15:06:27.000000000 +0200
@@ -12,7 +12,11 @@
 
 #include <assert.h>
 #include <inttypes.h>
+#if defined(WEBRTC_BSD)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #include "webrtc/common_types.h"
 
