--- ui/gfx/font_fallback_linux.cc.orig	2019-09-09 21:55:46 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -18,6 +18,10 @@
 #include "base/trace_event/trace_event.h"
 #include "ui/gfx/font.h"
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
