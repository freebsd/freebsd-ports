--- chrome/browser/extensions/activity_log/activity_log.cc.orig	2019-06-04 18:55:17 UTC
+++ chrome/browser/extensions/activity_log/activity_log.cc
@@ -53,7 +53,11 @@
 #include "extensions/browser/extensions_browser_client.h"
 #include "extensions/common/extension.h"
 #include "extensions/common/extension_messages.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 namespace constants = activity_log_constants;
