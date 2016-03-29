--- components/plugins/renderer/plugin_placeholder.cc.orig	2016-03-05 21:19:00.436550513 +0100
+++ components/plugins/renderer/plugin_placeholder.cc	2016-03-05 21:20:14.436562091 +0100
@@ -11,7 +11,11 @@
 #include "gin/object_template_builder.h"
 #include "third_party/WebKit/public/web/WebElement.h"
 #include "third_party/WebKit/public/web/WebPluginContainer.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace plugins {
 
