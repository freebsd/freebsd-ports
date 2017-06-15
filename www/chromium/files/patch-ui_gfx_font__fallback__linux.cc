--- ui/gfx/font_fallback_linux.cc.orig	2017-04-19 19:06:54 UTC
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
