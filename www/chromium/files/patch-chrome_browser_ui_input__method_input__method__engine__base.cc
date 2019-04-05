--- chrome/browser/ui/input_method/input_method_engine_base.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/browser/ui/input_method/input_method_engine_base.cc
@@ -29,7 +29,7 @@
 #include "ui/base/ime/chromeos/ime_keymap.h"
 #elif defined(OS_WIN)
 #include "ui/events/keycodes/keyboard_codes_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/events/keycodes/keyboard_codes_posix.h"
 #endif
 
