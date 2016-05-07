--- chrome/browser/ui/webui/extensions/extension_loader_handler.cc.orig	2016-03-05 21:09:24.961590217 +0100
+++ chrome/browser/ui/webui/extensions/extension_loader_handler.cc	2016-03-05 21:09:41.001588829 +0100
@@ -25,7 +25,11 @@
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
