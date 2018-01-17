--- src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc.orig	2017-01-26 00:49:31 UTC
+++ src/3rdparty/chromium/ui/gfx/font_fallback_linux.cc
@@ -15,6 +15,10 @@
 #include "base/memory/ptr_util.h"
 #include "ui/gfx/font.h"
 
+#if defined(OS_BSD)
+#  include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
