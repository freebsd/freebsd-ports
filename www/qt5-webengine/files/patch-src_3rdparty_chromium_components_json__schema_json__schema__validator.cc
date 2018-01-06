--- src/3rdparty/chromium/components/json_schema/json_schema_validator.cc.orig	2017-01-26 00:49:11 UTC
+++ src/3rdparty/chromium/components/json_schema/json_schema_validator.cc
@@ -21,7 +21,11 @@
 #include "base/strings/stringprintf.h"
 #include "base/values.h"
 #include "components/json_schema/json_schema_constants.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace schema = json_schema_constants;
 
