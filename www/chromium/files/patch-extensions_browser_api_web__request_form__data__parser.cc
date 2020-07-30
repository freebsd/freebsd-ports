--- extensions/browser/api/web_request/form_data_parser.cc.orig	2020-07-07 21:57:38 UTC
+++ extensions/browser/api/web_request/form_data_parser.cc
@@ -16,7 +16,11 @@
 #include "base/values.h"
 #include "net/base/escape.h"
 #include "net/http/http_request_headers.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using base::DictionaryValue;
 using base::ListValue;
