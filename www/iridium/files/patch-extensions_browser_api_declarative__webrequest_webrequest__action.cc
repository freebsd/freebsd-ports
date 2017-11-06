--- extensions/browser/api/declarative_webrequest/webrequest_action.cc.orig	2017-04-19 19:06:34 UTC
+++ extensions/browser/api/declarative_webrequest/webrequest_action.cc
@@ -29,7 +29,11 @@
 #include "net/base/registry_controlled_domains/registry_controlled_domain.h"
 #include "net/http/http_util.h"
 #include "net/url_request/url_request.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using content::ResourceRequestInfo;
 
