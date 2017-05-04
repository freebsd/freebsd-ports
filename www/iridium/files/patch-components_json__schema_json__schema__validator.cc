--- components/json_schema/json_schema_validator.cc.orig	2017-04-19 19:06:32 UTC
+++ components/json_schema/json_schema_validator.cc
@@ -20,7 +20,11 @@
 #include "base/strings/stringprintf.h"
 #include "base/values.h"
 #include "components/json_schema/json_schema_constants.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace schema = json_schema_constants;
 
