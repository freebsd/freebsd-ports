--- ui/base/ime/input_method_factory.cc.orig	2016-10-06 04:02:44.000000000 +0300
+++ ui/base/ime/input_method_factory.cc	2016-10-13 09:19:24.642495000 +0300
@@ -14,8 +14,8 @@
 #include "ui/base/ime/input_method_win.h"
 #elif defined(OS_MACOSX)
 #include "ui/base/ime/input_method_mac.h"
-#elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11) && \
-      !defined(OS_CHROMEOS)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD)) && \
+	defined(USE_X11) && !defined(OS_CHROMEOS)
 #include "ui/base/ime/input_method_auralinux.h"
 #elif defined(OS_ANDROID)
 #include "ui/base/ime/input_method_android.h"
@@ -56,8 +56,8 @@
   return base::MakeUnique<InputMethodWin>(delegate, widget);
 #elif defined(OS_MACOSX)
   return base::MakeUnique<InputMethodMac>(delegate);
-#elif defined(USE_AURA) && defined(OS_LINUX) && defined(USE_X11) && \
-      !defined(OS_CHROMEOS)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD)) && \
+  defined(USE_X11) && !defined(OS_CHROMEOS)
   return base::MakeUnique<InputMethodAuraLinux>(delegate);
 #elif defined(OS_ANDROID)
   return base::MakeUnique<InputMethodAndroid>(delegate);
