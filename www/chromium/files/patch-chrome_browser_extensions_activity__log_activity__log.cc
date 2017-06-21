--- chrome/browser/extensions/activity_log/activity_log.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/extensions/activity_log/activity_log.cc
@@ -50,7 +50,11 @@
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
