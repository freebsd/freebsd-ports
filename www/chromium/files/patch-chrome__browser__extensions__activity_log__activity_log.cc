--- chrome/browser/extensions/activity_log/activity_log.cc.orig	2016-03-05 21:02:01.319620815 +0100
+++ chrome/browser/extensions/activity_log/activity_log.cc	2016-03-05 21:02:58.927616965 +0100
@@ -39,7 +39,11 @@
 #include "extensions/browser/extensions_browser_client.h"
 #include "extensions/common/extension.h"
 #include "extensions/common/one_shot_event.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 namespace constants = activity_log_constants;
