--- components/dom_distiller/core/page_features.cc.orig	2016-07-22 00:06:53.000000000 -0400
+++ components/dom_distiller/core/page_features.cc	2016-08-03 11:25:37.908892000 -0400
@@ -10,7 +10,11 @@
 #include <string>
 
 #include "base/json/json_reader.h"
-#include "third_party/re2/src/re2/re2.h"
+#if defined(OS_FREEBSD)
+#  include <re2/re2.h>
+#else
+#  include "third_party/re2/src/re2/re2.h"
+#endif  // defined(OS_FREEBSD)
 #include "url/gurl.h"
 
 namespace dom_distiller {
