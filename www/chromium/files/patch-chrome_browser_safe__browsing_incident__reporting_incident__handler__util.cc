--- chrome/browser/safe_browsing/incident_reporting/incident_handler_util.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/safe_browsing/incident_reporting/incident_handler_util.cc
@@ -8,7 +8,11 @@
 
 #include "base/hash/hash.h"
 #include "base/notreached.h"
+#if defined(USE_SYSTEM_PROTOBUF)
+#include <google/protobuf/message_lite.h>
+#else
 #include "third_party/protobuf/src/google/protobuf/message_lite.h"
+#endif
 
 namespace safe_browsing {
 
