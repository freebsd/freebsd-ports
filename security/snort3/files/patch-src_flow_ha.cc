--- src/flow/ha.cc.orig	2019-07-31 09:26:02 UTC
+++ src/flow/ha.cc
@@ -35,6 +35,7 @@
 #include "flow_key.h"
 #include "ha_module.h"
 #include "session.h"
+#include <array>
 
 using namespace snort;
 
