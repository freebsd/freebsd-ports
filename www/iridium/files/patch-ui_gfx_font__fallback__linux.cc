--- ui/gfx/font_fallback_linux.cc.orig	2022-03-28 18:11:04 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -24,6 +24,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
