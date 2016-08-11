--- components/dom_distiller/core/page_features.cc.orig	2016-05-25 15:00:59.000000000 -0400
+++ components/dom_distiller/core/page_features.cc	2016-05-27 10:13:11.588307000 -0400
@@ -10,7 +10,11 @@
 
 #include "base/json/json_reader.h"
 #include "base/memory/scoped_ptr.h"
-#include "third_party/re2/src/re2/re2.h"
+#if defined(OS_BSD)
+#  include <re2/re2.h>
+#else
+#  include "third_party/re2/src/re2/re2.h"
+#endif // defined(OS_BSD)
 #include "url/gurl.h"
 
 namespace dom_distiller {
