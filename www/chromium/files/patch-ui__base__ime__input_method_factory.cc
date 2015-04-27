--- ui/base/ime/input_method_factory.cc.orig	2015-04-19 17:31:55.000000000 +0200
+++ ui/base/ime/input_method_factory.cc	2015-04-19 17:33:24.000000000 +0200
@@ -14,7 +14,7 @@
 #include "ui/base/ime/remote_input_method_win.h"
 #elif defined(OS_MACOSX)
 #include "ui/base/ime/input_method_mac.h"
-#elif defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/base/ime/input_method_auralinux.h"
 #else
 #include "ui/base/ime/input_method_minimal.h"
@@ -47,7 +47,7 @@
   return make_scoped_ptr(new InputMethodWin(delegate, widget));
 #elif defined(OS_MACOSX)
   return make_scoped_ptr(new InputMethodMac(delegate));
-#elif defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   return make_scoped_ptr(new InputMethodAuraLinux(delegate));
 #else
   return make_scoped_ptr(new InputMethodMinimal(delegate));
