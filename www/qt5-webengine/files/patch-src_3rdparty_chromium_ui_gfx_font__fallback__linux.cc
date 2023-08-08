--- src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc
@@ -24,6 +24,10 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
