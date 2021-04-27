--- ui/gfx/font_fallback_linux.cc.orig	2021-04-14 18:41:39 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -24,6 +24,10 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
