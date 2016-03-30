--- extensions/browser/api/web_request/form_data_parser.cc.orig	2016-03-05 21:31:37.080498500 +0100
+++ extensions/browser/api/web_request/form_data_parser.cc	2016-03-05 21:31:50.448497605 +0100
@@ -15,7 +15,11 @@
 #include "base/values.h"
 #include "net/base/escape.h"
 #include "net/url_request/url_request.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using base::DictionaryValue;
 using base::ListValue;
