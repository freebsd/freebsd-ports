--- widget/gtk/nsAppShell.cpp.orig	2026-09-24 10:45:55 UTC
+++ widget/gtk/nsAppShell.cpp
@@ -30,9 +30,9 @@
 #ifdef MOZ_ENABLE_DBUS
 #  include <gio/gio.h>
 
-#  include "WidgetUtilsGtk.h"
 #endif
+#include "WidgetUtilsGtk.h"
 #include "HeadlessScreenHelper.h"
 #include "ScreenHelperGTK.h"
 #include "WakeLockListener.h"
