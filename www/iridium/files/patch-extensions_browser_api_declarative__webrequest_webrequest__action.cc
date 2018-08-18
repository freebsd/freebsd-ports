--- extensions/browser/api/declarative_webrequest/webrequest_action.cc.orig	2018-03-20 23:05:25.000000000 +0100
+++ extensions/browser/api/declarative_webrequest/webrequest_action.cc	2018-03-24 17:41:04.749250000 +0100
@@ -28,7 +28,11 @@
 #include "extensions/common/extension.h"
 #include "net/base/registry_controlled_domains/registry_controlled_domain.h"
 #include "net/http/http_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using content::ResourceRequestInfo;
 
