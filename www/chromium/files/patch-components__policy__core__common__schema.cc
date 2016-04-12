--- components/policy/core/common/schema.cc.orig	2016-03-05 19:30:39.179235992 +0100
+++ components/policy/core/common/schema.cc	2016-03-05 19:31:28.596994984 +0100
@@ -21,7 +21,11 @@
 #include "components/json_schema/json_schema_constants.h"
 #include "components/json_schema/json_schema_validator.h"
 #include "components/policy/core/common/schema_internal.h"
+#if defined(OS_FREEBSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace schema = json_schema_constants;
 
