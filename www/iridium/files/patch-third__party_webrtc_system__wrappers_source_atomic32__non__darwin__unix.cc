--- third_party/webrtc/system_wrappers/source/atomic32_non_darwin_unix.cc.orig	2017-04-19 19:07:53 UTC
+++ third_party/webrtc/system_wrappers/source/atomic32_non_darwin_unix.cc
@@ -12,7 +12,7 @@
 
 #include <assert.h>
 #include <inttypes.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "webrtc/common_types.h"
 
