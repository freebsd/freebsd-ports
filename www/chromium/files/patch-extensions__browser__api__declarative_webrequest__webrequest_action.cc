--- extensions/browser/api/declarative_webrequest/webrequest_action.cc.orig	2016-03-05 21:30:23.744503770 +0100
+++ extensions/browser/api/declarative_webrequest/webrequest_action.cc	2016-03-05 21:30:38.440502352 +0100
@@ -28,7 +28,11 @@
 #include "net/base/registry_controlled_domains/registry_controlled_domain.h"
 #include "net/http/http_util.h"
 #include "net/url_request/url_request.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using content::ResourceRequestInfo;
 
