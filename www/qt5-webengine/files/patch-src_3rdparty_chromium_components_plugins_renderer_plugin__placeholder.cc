--- src/3rdparty/chromium/components/plugins/renderer/plugin_placeholder.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/components/plugins/renderer/plugin_placeholder.cc
@@ -11,7 +11,11 @@
 #include "gin/object_template_builder.h"
 #include "third_party/blink/public/web/web_element.h"
 #include "third_party/blink/public/web/web_plugin_container.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace plugins {
 
