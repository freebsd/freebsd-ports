--- ui/gfx/font_fallback_linux.cc.orig	2022-04-01 07:48:30 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -25,6 +25,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
