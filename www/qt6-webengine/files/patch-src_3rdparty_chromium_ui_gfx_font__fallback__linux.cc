--- src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc
@@ -26,6 +26,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
