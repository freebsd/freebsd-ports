--- chrome/browser/extensions/activity_log/activity_log.cc.orig	2021-12-14 11:44:58 UTC
+++ chrome/browser/extensions/activity_log/activity_log.cc
@@ -51,7 +51,11 @@
 #include "extensions/common/features/feature_provider.h"
 #include "extensions/common/hashed_extension_id.h"
 #include "extensions/common/mojom/renderer.mojom.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 namespace constants = activity_log_constants;
