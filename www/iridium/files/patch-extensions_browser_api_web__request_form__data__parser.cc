--- extensions/browser/api/web_request/form_data_parser.cc.orig	2019-03-11 22:00:58 UTC
+++ extensions/browser/api/web_request/form_data_parser.cc
@@ -15,7 +15,11 @@
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
