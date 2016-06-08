--- ui/gfx/font_fallback_linux.cc.orig	2016-05-27 10:26:15.843855000 -0400
+++ ui/gfx/font_fallback_linux.cc	2016-05-27 10:26:38.723265000 -0400
@@ -15,6 +15,10 @@
 #include "base/memory/ptr_util.h"
 #include "ui/gfx/font.h"
 
+#if defined(OS_BSD)
+#  include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
