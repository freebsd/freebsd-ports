--- third_party/webrtc/p2p/base/port.cc.orig	2017-12-30 23:29:20.335693000 +0100
+++ third_party/webrtc/p2p/base/port.cc	2017-12-30 23:29:34.422422000 +0100
@@ -10,6 +10,8 @@
 
 #include "p2p/base/port.h"
 
+#include <math.h>
+
 #include <algorithm>
 #include <vector>
 
