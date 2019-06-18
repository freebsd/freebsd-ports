--- chrome/browser/extensions/activity_log/activity_log.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/extensions/activity_log/activity_log.cc
@@ -52,7 +52,11 @@
 #include "extensions/common/extension.h"
 #include "extensions/common/extension_messages.h"
 #include "extensions/common/one_shot_event.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 namespace constants = activity_log_constants;
