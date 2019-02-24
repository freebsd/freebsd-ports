--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2019-01-30 02:20:37.000000000 +0100
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc	2019-02-01 13:38:23.452214000 +0100
@@ -12,6 +12,7 @@
 
 #include <string.h>
 #include <algorithm>
+#include <cstdlib>
 #include <utility>
 
 #include "modules/include/module_common_types_public.h"
