--- chrome/browser/extensions/activity_log/activity_log.cc.orig	2021-01-18 21:28:49 UTC
+++ chrome/browser/extensions/activity_log/activity_log.cc
@@ -49,7 +49,11 @@
 #include "extensions/common/extension.h"
 #include "extensions/common/extension_messages.h"
 #include "extensions/common/mojom/renderer.mojom.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 namespace constants = activity_log_constants;
