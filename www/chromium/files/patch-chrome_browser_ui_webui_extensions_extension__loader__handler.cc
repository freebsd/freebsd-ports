--- chrome/browser/ui/webui/extensions/extension_loader_handler.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/ui/webui/extensions/extension_loader_handler.cc
@@ -27,7 +27,11 @@
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
