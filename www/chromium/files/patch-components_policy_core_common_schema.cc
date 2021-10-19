--- components/policy/core/common/schema.cc.orig	2021-09-14 01:51:55 UTC
+++ components/policy/core/common/schema.cc
@@ -25,7 +25,11 @@
 #include "base/strings/stringprintf.h"
 #include "components/policy/core/common/json_schema_constants.h"
 #include "components/policy/core/common/schema_internal.h"
+#if defined(OS_FREEBSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace schema = json_schema_constants;
 
