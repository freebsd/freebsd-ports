--- ui/base/ime/input_method_factory.cc.orig	2016-07-22 00:07:12.000000000 -0400
+++ ui/base/ime/input_method_factory.cc	2016-08-03 16:35:19.855521000 -0400
@@ -15,7 +15,7 @@
 #elif defined(OS_MACOSX)
 #include "ui/base/ime/input_method_mac.h"
 #elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11) && \
-      !defined(OS_CHROMEOS)
+      !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/base/ime/input_method_auralinux.h"
 #elif defined(OS_ANDROID)
 #include "ui/base/ime/input_method_android.h"
@@ -57,7 +57,7 @@
 #elif defined(OS_MACOSX)
   return base::WrapUnique(new InputMethodMac(delegate));
 #elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11) && \
-      !defined(OS_CHROMEOS)
+      !defined(OS_CHROMEOS) || defined(OS_BSD)
   return base::WrapUnique(new InputMethodAuraLinux(delegate));
 #elif defined(OS_ANDROID)
   return base::WrapUnique(new InputMethodAndroid(delegate));
