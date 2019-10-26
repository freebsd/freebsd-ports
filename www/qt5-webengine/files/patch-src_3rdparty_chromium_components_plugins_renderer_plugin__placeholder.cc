--- src/3rdparty/chromium/components/plugins/renderer/plugin_placeholder.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/plugins/renderer/plugin_placeholder.cc
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
 
