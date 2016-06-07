--- ui/base/ime/input_method_factory.cc.orig	2016-05-11 19:02:35 UTC
+++ ui/base/ime/input_method_factory.cc
@@ -14,7 +14,7 @@
 #elif defined(OS_MACOSX)
 #include "ui/base/ime/input_method_mac.h"
 #elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11) && \
-      !defined(OS_CHROMEOS)
+      !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/base/ime/input_method_auralinux.h"
 #elif defined(OS_ANDROID)
 #include "ui/base/ime/input_method_android.h"
@@ -56,7 +56,7 @@ scoped_ptr<InputMethod> CreateInputMetho
 #elif defined(OS_MACOSX)
   return make_scoped_ptr(new InputMethodMac(delegate));
 #elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11) && \
-      !defined(OS_CHROMEOS)
+      !defined(OS_CHROMEOS) || defined(OS_BSD)
   return make_scoped_ptr(new InputMethodAuraLinux(delegate));
 #elif defined(OS_ANDROID)
   return make_scoped_ptr(new InputMethodAndroid(delegate));
