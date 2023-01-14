--- src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc
@@ -25,6 +25,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
