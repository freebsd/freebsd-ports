--- components/dom_distiller/core/page_features.cc.orig	2016-03-05 21:23:13.237533214 +0100
+++ components/dom_distiller/core/page_features.cc	2016-03-05 21:23:28.813592348 +0100
@@ -9,7 +9,11 @@
 #include <string>
 
 #include "base/json/json_reader.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 namespace dom_distiller {
