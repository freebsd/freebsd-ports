--- chrome/browser/ui/input_method/input_method_engine_base.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/ui/input_method/input_method_engine_base.cc
@@ -37,7 +37,7 @@
 #elif defined(OS_WIN)
 #include "ui/events/keycodes/dom/keycode_converter.h"
 #include "ui/events/keycodes/keyboard_codes_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/events/keycodes/dom/keycode_converter.h"
 #include "ui/events/keycodes/keyboard_codes_posix.h"
 #endif
