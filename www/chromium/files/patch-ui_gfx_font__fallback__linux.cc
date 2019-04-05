--- ui/gfx/font_fallback_linux.cc.orig	2019-03-11 22:01:19 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -15,6 +15,10 @@
 #include "base/memory/ptr_util.h"
 #include "ui/gfx/font.h"
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
