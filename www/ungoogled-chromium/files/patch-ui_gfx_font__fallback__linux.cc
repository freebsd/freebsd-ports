--- ui/gfx/font_fallback_linux.cc.orig	2022-10-01 07:40:07 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -26,6 +26,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
