--- src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc
@@ -32,6 +32,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
