--- ui/base/ime/input_method_factory.cc.orig	2015-08-22 15:01:59.000000000 -0400
+++ ui/base/ime/input_method_factory.cc	2015-09-03 11:38:57.103095000 -0400
@@ -15,7 +15,7 @@
 #elif defined(OS_MACOSX)
 #include "ui/base/ime/input_method_mac.h"
 #elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11) && \
-      !defined(OS_CHROMEOS)
+      !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/base/ime/input_method_auralinux.h"
 #else
 #include "ui/base/ime/input_method_minimal.h"
@@ -57,7 +57,7 @@
 #elif defined(OS_MACOSX)
   return make_scoped_ptr(new InputMethodMac(delegate));
 #elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11) && \
-      !defined(OS_CHROMEOS)
+      !defined(OS_CHROMEOS) || defined(OS_BSD)
   return make_scoped_ptr(new InputMethodAuraLinux(delegate));
 #else
   return make_scoped_ptr(new InputMethodMinimal(delegate));
