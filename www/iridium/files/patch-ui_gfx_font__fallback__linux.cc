--- ui/gfx/font_fallback_linux.cc.orig	2025-09-11 13:19:19 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -28,6 +28,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
