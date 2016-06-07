--- chrome/browser/safe_browsing/incident_reporting/incident_handler_util.cc.orig	2016-03-25 13:04:45 UTC
+++ chrome/browser/safe_browsing/incident_reporting/incident_handler_util.cc
@@ -8,7 +8,12 @@
 
 #include "base/hash.h"
 #include "base/logging.h"
+//XXX(rene) needs shim headers?
+#if defined(USE_SYSTEM_PROTOBUF)
+#include <google/protobuf/message_lite.h>
+#else
 #include "third_party/protobuf/src/google/protobuf/message_lite.h"
+#endif
 
 namespace safe_browsing {
 
