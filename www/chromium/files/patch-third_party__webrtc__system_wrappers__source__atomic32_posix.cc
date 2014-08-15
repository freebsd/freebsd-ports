--- ./third_party/webrtc/system_wrappers/source/atomic32_posix.cc.orig	2014-08-12 21:04:15.000000000 +0200
+++ ./third_party/webrtc/system_wrappers/source/atomic32_posix.cc	2014-08-13 09:57:00.000000000 +0200
@@ -12,7 +12,11 @@
 
 #include <assert.h>
 #include <inttypes.h>
+#if defined(WEBRTC_BSD)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #include "webrtc/common_types.h"
 
