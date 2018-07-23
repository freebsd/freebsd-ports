--- extensions/browser/api/web_request/form_data_parser.cc.orig	2018-06-13 00:10:18.000000000 +0200
+++ extensions/browser/api/web_request/form_data_parser.cc	2018-07-19 13:36:19.375722000 +0200
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
