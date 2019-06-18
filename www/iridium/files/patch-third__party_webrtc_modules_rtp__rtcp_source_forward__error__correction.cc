--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2019-03-11 22:08:10 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -12,6 +12,7 @@
 
 #include <string.h>
 #include <algorithm>
+#include <cstdlib>
 #include <utility>
 
 #include "modules/include/module_common_types_public.h"
