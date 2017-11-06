--- components/plugins/renderer/plugin_placeholder.cc.orig	2017-04-19 19:06:33 UTC
+++ components/plugins/renderer/plugin_placeholder.cc
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
 
