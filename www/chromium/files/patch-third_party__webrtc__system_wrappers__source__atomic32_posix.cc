--- third_party/webrtc/system_wrappers/source/atomic32_posix.cc.orig	2013-07-16 17:22:11.000000000 +0300
+++ third_party/webrtc/system_wrappers/source/atomic32_posix.cc	2013-07-16 17:23:12.000000000 +0300
@@ -12,7 +12,11 @@
 
 #include <assert.h>
 #include <inttypes.h>
+#if defined(WEBRTC_BSD)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #include "common_types.h"
 
