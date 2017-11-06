--- ui/base/ime/input_method_factory.cc.orig	2017-04-19 19:06:54 UTC
+++ ui/base/ime/input_method_factory.cc
@@ -16,7 +16,8 @@
 #include "ui/base/ime/input_method_win.h"
 #elif defined(OS_MACOSX)
 #include "ui/base/ime/input_method_mac.h"
-#elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD)) && \
+      defined(USE_X11)
 #include "ui/base/ime/input_method_auralinux.h"
 #elif defined(OS_ANDROID)
 #include "ui/base/ime/input_method_android.h"
@@ -60,7 +61,8 @@ std::unique_ptr<InputMethod> CreateInput
   return base::MakeUnique<InputMethodWin>(delegate, widget);
 #elif defined(OS_MACOSX)
   return base::MakeUnique<InputMethodMac>(delegate);
-#elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD)) && \
+      defined(USE_X11)
   return base::MakeUnique<InputMethodAuraLinux>(delegate);
 #elif defined(OS_ANDROID)
   return base::MakeUnique<InputMethodAndroid>(delegate);
