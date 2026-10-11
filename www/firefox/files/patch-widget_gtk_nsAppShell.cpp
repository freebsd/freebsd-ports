commit a24a54330b877e5cc437da03f0895548c137162f
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    fix build with DBUS disabled
    
    error message:
    
    In file included from /wrkdirs/usr/ports/www/firefox/work/.build/widget/gtk/Unified_cpp_widget_gtk2.cpp:38:
    /wrkdirs/usr/ports/www/firefox/work/firefox-158.0/widget/gtk/nsAppShell.cpp:629:9: error: use of undeclared identifier 'IsGnomeDesktopEnvironment'
      629 |     if (IsGnomeDesktopEnvironment()) {
          |         ^

diff --git widget/gtk/nsAppShell.cpp widget/gtk/nsAppShell.cpp
index 84f3b84894de..014316d5c4f1 100644
--- widget/gtk/nsAppShell.cpp
+++ widget/gtk/nsAppShell.cpp
@@ -29,9 +29,10 @@
 #include "prenv.h"
 #ifdef MOZ_ENABLE_DBUS
 #  include <gio/gio.h>
+#endif
 
 #  include "WidgetUtilsGtk.h"
-#endif
+
 #include "HeadlessScreenHelper.h"
 #include "ScreenHelperGTK.h"
 #include "WakeLockListener.h"
