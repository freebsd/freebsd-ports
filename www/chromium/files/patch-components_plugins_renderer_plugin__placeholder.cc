--- components/plugins/renderer/plugin_placeholder.cc.orig	2018-06-13 00:10:13.000000000 +0200
+++ components/plugins/renderer/plugin_placeholder.cc	2018-07-19 00:02:51.619981000 +0200
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
 
