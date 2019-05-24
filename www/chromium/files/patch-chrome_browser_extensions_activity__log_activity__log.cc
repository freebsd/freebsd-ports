--- chrome/browser/extensions/activity_log/activity_log.cc.orig	2019-04-30 22:22:33 UTC
+++ chrome/browser/extensions/activity_log/activity_log.cc
@@ -53,7 +53,11 @@
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
