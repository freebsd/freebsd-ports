--- third_party/webrtc/system_wrappers/source/atomic32_non_darwin_unix.cc.orig	2016-10-06 04:05:36.000000000 +0300
+++ third_party/webrtc/system_wrappers/source/atomic32_non_darwin_unix.cc	2016-10-14 17:25:37.203869000 +0300
@@ -12,7 +12,7 @@
 
 #include <assert.h>
 #include <inttypes.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "webrtc/common_types.h"
 
