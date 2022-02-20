--- ui/gfx/font_fallback_linux.cc.orig	2022-02-07 13:39:41 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -24,6 +24,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
