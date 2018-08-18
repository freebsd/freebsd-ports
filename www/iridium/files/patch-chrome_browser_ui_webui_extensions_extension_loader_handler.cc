--- chrome/browser/ui/webui/extensions/extension_loader_handler.cc.orig	2018-08-16 13:00:53.692954000 +0200
+++ chrome/browser/ui/webui/extensions/extension_loader_handler.cc	2018-08-16 13:01:28.004036000 +0200
@@ -30,7 +30,11 @@
 #include "extensions/common/constants.h"
 #include "extensions/common/extension.h"
 #include "extensions/common/manifest_constants.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "ui/base/l10n/l10n_util.h"
 
 namespace extensions {
