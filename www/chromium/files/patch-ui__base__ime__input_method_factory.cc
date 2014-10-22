--- ui/base/ime/input_method_factory.cc.orig	2014-10-14 21:31:49.000000000 +0200
+++ ui/base/ime/input_method_factory.cc	2014-10-14 21:26:34.000000000 +0200
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
   return scoped_ptr<InputMethod>(new InputMethodWin(delegate, widget));
 #elif defined(OS_MACOSX)
   return scoped_ptr<InputMethod>(new InputMethodMac(delegate));
-#elif defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   return scoped_ptr<InputMethod>(new InputMethodAuraLinux(delegate));
 #else
   return scoped_ptr<InputMethod>(new InputMethodMinimal(delegate));
