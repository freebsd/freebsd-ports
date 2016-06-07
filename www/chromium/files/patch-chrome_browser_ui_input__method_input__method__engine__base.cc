--- chrome/browser/ui/input_method/input_method_engine_base.cc.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/input_method/input_method_engine_base.cc
@@ -35,7 +35,7 @@
 #elif defined(OS_WIN)
 #include "ui/events/keycodes/dom/keycode_converter.h"
 #include "ui/events/keycodes/keyboard_codes_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/events/keycodes/dom/keycode_converter.h"
 #include "ui/events/keycodes/keyboard_codes_posix.h"
 #endif
