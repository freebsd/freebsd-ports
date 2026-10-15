--- cef/libcef/browser/native/cursor_util_aura.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/native/cursor_util_aura.cc
@@ -14,7 +14,7 @@
 #include "ui/display/screen.h"
 #include "ui/wm/core/cursor_loader.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ozone_buildflags.h"
 #if BUILDFLAG(SUPPORTS_OZONE_X11)
 #include "ui/base/x/x11_cursor.h"
