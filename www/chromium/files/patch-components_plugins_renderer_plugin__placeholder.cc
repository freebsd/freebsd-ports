--- components/plugins/renderer/plugin_placeholder.cc.orig	2019-01-30 02:17:54.000000000 +0100
+++ components/plugins/renderer/plugin_placeholder.cc	2019-02-01 00:04:53.895073000 +0100
@@ -17,7 +17,11 @@
 #include "third_party/blink/public/web/web_plugin_container.h"
 #include "third_party/blink/public/web/web_script_source.h"
 #include "third_party/blink/public/web/web_serialized_script_value.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif // defined(OS_BSD)
 
 namespace plugins {
 
